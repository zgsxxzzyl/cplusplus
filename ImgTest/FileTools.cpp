#include "FileTools.h"
#include "ImageTools.h"
#include <io.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
static const string g_FILE_SEPARATOR = "\\";

std::vector<File> getFileFromSrc(string src)
{
	vector<File> files;
	File file;
	intptr_t _handle;
	_finddata_t _data;
	string _parentPath = addSepIfSrcIsDir(src);
	string path = _parentPath + "*.*";
	_handle = _findfirst(path.c_str(),&_data);

	cout << "begin Path: " << path <<endl;
	if (_handle == -1)
	{
		return files;
	}
	do 
	{
		if (_data.attrib & _A_SUBDIR
			|| strcmp(_data.name,".") == 0
			|| strcmp(_data.name,"..") == 0
			)
		{
			cout << "skip dir " << _data.name <<endl;
		}
		else
		{
			file.fullname = _data.name;
			size_t i = file.fullname.find_last_of(".");
			file.name = file.fullname.substr(0, i);
			file.type = file.fullname.substr(i + 1);      //remov
			file.parentPath = _parentPath;
			file.absolutePath = _parentPath+_data.name;
			files.push_back(file);
		}
	} while (_findnext(_handle,&_data)==0);

	return files;
}

std::string addSepIfSrcIsDir(string src)
{
	intptr_t _handle;
	_finddata_t data;

	_handle = _findfirst(src.c_str(),&data);
	if (_handle == -1)
	{
		return src;
	}
	if (g_FILE_SEPARATOR.compare(&src[src.size()-1])!=0)
	{
		src.append(g_FILE_SEPARATOR);
	}
	return src;
}

bool isFileExist(string src)
{
	fstream _in;

	_in.open(src);
	if (_in)
	{
		return true;
	}
	return false;
}

FileCompRes compareName(vector<File> src, vector<File> tar)
{
	FileCompRes fcr;
	multimap<string, File> mp_tar;

	for (int i = 0; i<tar.size(); i++)       //把新的转换成一个multimap
	{
		//cout << tar[i].name <<endl;
		mp_tar.insert(pair<string, File>(tar[i].name, tar[i]));
	}

	for (int i = 0; i<src.size(); i++)
	{
		size_t num = mp_tar.count(src[i].name);

		if (num > 0)
		{
			multimap<string, File>::iterator iter = mp_tar.find(src[i].name);

			if (iter != mp_tar.end())
			{
				for (int j = 0; j<num; j++)
				{
					//cout << iter->second.fullname << ":"<<src[i].fullname <<endl;
					if (iter->second.type.compare(src[i].type) == 0)
					{
						fcr.same.push_back(src[i]);
						break;
					}
					if (j == num - 1)
					{
						//cout << iter->second.fullname << ":" << src[i].fullname << endl;
						src[i].dy = TYPE;
						src[i].diffContent = iter->second.fullname;
						fcr.diff.push_back(src[i]);
					}
					iter++;
				}

			}
		}
		else
		{
			//cout << src[i].fullname << endl;
			src[i].dy = NAME;
			fcr.diff.push_back(src[i]);
		}

	}
	return fcr;
}


FileCompRes compareSize(vector<File> src,string path)
{
	FileCompRes fcr;
	for (int i = 0; i < src.size(); i++)
	{
		string src_pix = readPixel(src[i].absolutePath);
		string tar_pix = readPixel(path + "\\" + src[i].fullname);
		if (src_pix.compare(tar_pix) == 0)
		{
			fcr.same.push_back(src[i]);
		}
		else
		{
			src[i].dy = PIXEL;
			src[i].diffContent = src_pix + ":" + tar_pix;
			fcr.diff.push_back(src[i]);
		}
	}
	return fcr;
}

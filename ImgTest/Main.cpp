#include <string>  
#include <iostream>  
#include <fstream>
#include "FileTools.h"
using namespace std;  

int main(int argc,char **args)
{
	vector<File> src = getFileFromSrc("E:\\IMG\\CafeToolbar旧图标\\CafeToolbar第一版");
	vector<File> target = getFileFromSrc("E:\\IMG\\CafeToolbar新图标\\CafeToolbar第一版新图标");

	FileCompRes fcr_name = compareName(src,target);
	FileCompRes fcr_size = compareSize(fcr_name.same,"E:\\IMG\\CafeToolbar新图标\\CafeToolbar第一版新图标");

	vector<File> srcOther = getFileFromSrc("E:\\IMG\\CafeToolbar旧图标\\cafe图标补充\\cafe图标补充");
	vector<File> targetOther = getFileFromSrc("E:\\IMG\\CafeToolbar新图标\\cafe新图标补充");

	FileCompRes fcr_nameOther = compareName(srcOther, targetOther);
	FileCompRes fcr_sizeOther = compareSize(fcr_nameOther.same, "E:\\IMG\\CafeToolbar新图标\\cafe新图标补充");

	ofstream out;

	out.open("result.txt");
	out << "名字或者类型不相同的文件如下：" << endl;
	for (size_t i = 0; i < fcr_name.diff.size(); i++)
	{
		out << fcr_name.diff[i].absolutePath << "---"<<fcr_name.diff[i].diffContent << "---"<< fcr_name.diff[i].dy<< endl;
	}
	for (size_t i = 0; i < fcr_nameOther.diff.size(); i++)
	{
		out << fcr_nameOther.diff[i].absolutePath << "---" << fcr_nameOther.diff[i].diffContent << "---" << fcr_nameOther.diff[i].dy << endl;
	}
	out << "像素不相同的如下：" << endl;
	for (size_t i = 0; i < fcr_size.diff.size(); i++)
	{
		out << fcr_size.diff[i].absolutePath << "---" << fcr_size.diff[i].diffContent << "---" << fcr_size.diff[i].dy << endl;
	}
	for (size_t i = 0; i < fcr_sizeOther.diff.size(); i++)
	{
		out << fcr_sizeOther.diff[i].absolutePath << "---" << fcr_sizeOther.diff[i].diffContent << "---" << fcr_sizeOther.diff[i].dy << endl;
	}
	out.close();

	cout << "" << endl;
	cin.get();
	return 0;
}
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
void readTxt(string);
int readfile()
{
	readTxt("database.csv");
	return 0;
}


void readTxt(string file)
{
	ifstream infile; 
	infile.open(file.data());   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

	char c;
	//infile >> noskipws;
	streampos pos;
	char line[256];
	string str;
	while (!infile.eof())
	{
		memset(line,0,256);
		infile.getline(line,256);
		str  = line;
		pos = infile.tellg();
		cout << line << "---"<< str.length()<<"---" <<pos << endl;
		/*	pos = infile.tellg();
		infile >> noskipws;
		infile>>c;
		cout<<c;*/
	}
	infile.close();             //关闭文件输入流 
	cin.get();
	return;
}

bool copy_binary_file(const char * szDestFile, const char * szOrigFile)  
{  
	if (szDestFile == NULL)  
	{  
		return false;  
	}  

	if (szOrigFile == NULL)  
	{  
		return false;  
	}

	bool bRet = true;

	std::ofstream fout(szDestFile, std::ios::binary | std::ios::app);  
	std::ifstream fin(szOrigFile, std::ios::binary);  

	if (fin.bad())  
	{  
		bRet = false;  
	}  
	else
	{  
		while(!fin.eof())  
		{  
			char szBuf[256] = {0};  
			fin.read(szBuf, sizeof(char) * 256);
			if (fout.bad())
			{  
				bRet = false;  
				break;  
			}  

			fout.write(szBuf, sizeof(char) * 256);  
		}  
	}

	fin.close();  
	fout.close();  

	return bRet;  
}  
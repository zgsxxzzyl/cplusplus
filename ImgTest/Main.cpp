#include <string>  
#include <iostream>  
#include <fstream>
#include "FileTools.h"
using namespace std;  

int main(int argc,char **args)
{
	vector<File> src = getFileFromSrc("E:\\IMG\\CafeToolbar��ͼ��\\CafeToolbar��һ��");
	vector<File> target = getFileFromSrc("E:\\IMG\\CafeToolbar��ͼ��\\CafeToolbar��һ����ͼ��");

	FileCompRes fcr_name = compareName(src,target);
	FileCompRes fcr_size = compareSize(fcr_name.same,"E:\\IMG\\CafeToolbar��ͼ��\\CafeToolbar��һ����ͼ��");

	vector<File> srcOther = getFileFromSrc("E:\\IMG\\CafeToolbar��ͼ��\\cafeͼ�겹��\\cafeͼ�겹��");
	vector<File> targetOther = getFileFromSrc("E:\\IMG\\CafeToolbar��ͼ��\\cafe��ͼ�겹��");

	FileCompRes fcr_nameOther = compareName(srcOther, targetOther);
	FileCompRes fcr_sizeOther = compareSize(fcr_nameOther.same, "E:\\IMG\\CafeToolbar��ͼ��\\cafe��ͼ�겹��");

	ofstream out;

	out.open("result.txt");
	out << "���ֻ������Ͳ���ͬ���ļ����£�" << endl;
	for (size_t i = 0; i < fcr_name.diff.size(); i++)
	{
		out << fcr_name.diff[i].absolutePath << "---"<<fcr_name.diff[i].diffContent << "---"<< fcr_name.diff[i].dy<< endl;
	}
	for (size_t i = 0; i < fcr_nameOther.diff.size(); i++)
	{
		out << fcr_nameOther.diff[i].absolutePath << "---" << fcr_nameOther.diff[i].diffContent << "---" << fcr_nameOther.diff[i].dy << endl;
	}
	out << "���ز���ͬ�����£�" << endl;
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
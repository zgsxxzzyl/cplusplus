#ifndef _FILE_TOOLS_H_
#define _FILE_TOOLS_H_
#include <vector>
using namespace std;

enum DiffType
{
	EMPTY, NAME, TYPE, PIXEL
};


struct File
{
	string name;
	string type;
	string fullname;
	string parentPath;
	string absolutePath;
	string diffContent;
	DiffType dy;
};

struct FileCompRes
{
	vector<File> same;
	vector<File> diff;
};

vector<File> getFileFromSrc(string);
string addSepIfSrcIsDir(string);
bool isFileExist(string);
FileCompRes compareName(vector<File>, vector<File>);
FileCompRes compareSize(vector<File>,string);
#endif

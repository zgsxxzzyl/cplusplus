typedef unsigned char BYTE;
//typedef unsigned short WORD;
#include "Image.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;
void readImageFileByPointer(ifstream &, BYTE*, streampos, streamoff);
int main()
{
	//const char * file = "E:\\IMG\\CafeToolbar旧图标\\CafeToolbar第一版\\action_clear_all_filters.png";
	//const char * file = "E:\\IMG\\CafeToolbar旧图标\\CafeToolbar第一版\\AboutBoxBanner.bmp";
	const char * file = "E:\\IMG\\CafeToolbar旧图标\\CafeToolbar第一版\\action_children.gif";
	ifstream infile(file, ios::binary);
	BYTE result[2];
	readImageFileByPointer(infile, result, 0, 2);
	short type;
	memcpy(&type, result,2);
	cout << "0x"<<hex << type<<":";
	if (type == 0x5089)
	{
		cout << "PNG" << endl;
		BYTE bwidth[4];
		BYTE bheight[4];
		readImageFileByPointer(infile, bwidth, 16, 4);
		readImageFileByPointer(infile, bheight, 20, 4);
		
		int width = bwidth[3] & 0xFF;
		width |= ((bwidth[2] << 8) & 0xFF00);
		width |= ((bwidth[1] << 16) & 0xFF0000);
		width |= ((bwidth[0] << 24) & 0xFF000000);

		int height = bheight[3] & 0xFF;
		height |= ((bheight[2] << 8) & 0xFF00);
		height |= ((bheight[1] << 16) & 0xFF0000);
		height |= ((bheight[0] << 24) & 0xFF000000);

		if (width == 16) {
			cout << width << ":" << height << endl;
		}
	}
	else if (type == 0x4D42)		//bmp
	{
		cout << "BMP" << endl;
		BITMAPFILEHEADER header = { 0 };
		BITMAPINFOHEADER info = { 0 };
		infile.seekg(0,ios_base::beg);
		infile.read((char *)&header, sizeof(BITMAPFILEHEADER));
		infile.read((char *)&info, sizeof(BITMAPINFOHEADER));
		long bmpWidth = info.biWidth;
		long bmpHeight = info.biHeight;
	}
	else if (type == 0x4947)
	{
		cout << "GIF" << endl;
		BYTE bwidth[2];
		BYTE bheight[2];
		readImageFileByPointer(infile, bwidth, 6, 2);
		readImageFileByPointer(infile, bheight, 8, 2);

		int width = bwidth[0] & 0xFF;
		width |= ((bwidth[1] << 8) & 0xFF00);

		int height = bheight[0] & 0xFF;
		height |= ((bheight[1] << 8) & 0xFF00);

		cout << dec << width << ":" << height << endl;
	}
	cin.get();
	return 0;
}

void readImageFileByPointer(ifstream &infile, BYTE* result, streampos pos = ios_base::cur, streamoff off = 0)
{
	if (!infile)
	{
		return;
	}
	infile.seekg(pos);
	infile.read((char *)result, off);
	return;
}
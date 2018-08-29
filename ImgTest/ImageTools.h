#pragma once
#ifndef _IMAGE_TOOLS_H_
#define _IMAGE_TOOLS_H_
typedef unsigned char BYTE;
#include <fstream>
#include <iostream>
#include <windows.h>
#include "FileTools.h"

using namespace std;
string readPixel(string);
void readImageFileByPointer(ifstream &, BYTE*, streampos, streamoff);
#endif // !_IMAGE_TOOLS_H_


#pragma once
#ifndef _IMAGE_H_
#define _IMAGE_H_

struct PNG
{
	int type;		//4
	char content[12];
	int width;
	int height;

};


#endif // !_IMAGE_H_

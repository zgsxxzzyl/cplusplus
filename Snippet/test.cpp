#include<iostream>
#include <vector>
#include <string>
#include <map>
#include "model.h"
using namespace std;

struct Demo 
{
	int a;
	int b;
};

map<int,Demo> mp_demo;
int test(int argc,char *argv[])
{
	Demo demo1;
	demo1.a = 1;
	demo1.b = 2;
	Demo demo2;
	demo2.a = 2;
	demo2.b = 6;
	std::pair<std::map<int,Demo>::iterator,bool> ret;
	ret = mp_demo.insert(pair<int,Demo>(demo1.a,demo1));
	mp_demo.insert(map<int,Demo>::value_type(demo2.a,demo2));

	return 0;
}

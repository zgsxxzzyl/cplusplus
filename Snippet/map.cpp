#include <map>  
#include <string>  
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;  

//map three method
map<int,string> mapstr;

void inA();
void inB();
void inC();
void outA();
void outB();
void outC();
void search();
void delA();

int main()  
{  
	inA();
	inB();
	inC();
	outA();
	outB();
	outC();
	search();
	delA();
	cin.get();
}

void inA()
{
	mapstr.clear();
	mapstr.insert(pair<int,string>(1,"student_one"));
	mapstr.insert(pair<int,string>(2,"student_two"));
	mapstr.insert(pair<int,string>(3,"student_three"));
}

void inB()
{
	mapstr.clear();
	mapstr.insert(map<int,string>::value_type(1,"student_one"));
	mapstr.insert(map<int,string>::value_type(2,"student_two"));
	pair<map<int,string>::iterator, bool> rt = mapstr.insert(map<int,string>::value_type(3,"student_three"));
	if (rt.second == true)
	{
		cout << "INSERT SUCCESSFUL" <<endl;
	}
	else
	{
		cout << "INSERT FAIL" <<endl;
	}

}

void inC()
{
	mapstr.clear();
	mapstr[1] = "student_one";
	mapstr[2] = "student_two";
	mapstr[3] = "student_three";
}

void outA()
{
	map<int, string>::iterator iter;  
	for (iter = mapstr.begin(); iter != mapstr.end(); iter++)
	{
		cout << iter->first << "---" <<iter->second<<endl;
	}
}

void outB()
{
	map<int, string>::reverse_iterator iter;  
	for(iter = mapstr.rbegin(); iter != mapstr.rend(); iter++)  
	{
		cout<<iter->first<<"  "<<iter->second<<endl;  
	}
}

void outC()
{
	int nSize = mapstr.size();  
	for(int i = 1;i<=nSize;i++)
	{
		cout << mapstr[i] <<endl;
	}
}

void search()
{
	map<int,string>::iterator iter = mapstr.find(1);
	if (iter != mapstr.end())
	{
		cout << iter->second <<endl;
	}
}


void delA()
{
	map<int, string>::iterator iter = mapstr.find(1);
	map<int, string>::iterator  a = mapstr.erase(iter);
	int b = mapstr.erase(2);
}
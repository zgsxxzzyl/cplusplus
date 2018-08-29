#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
vector<string> split(string,const char);
int demo()
{
	string res = "17;\"_testCube##e17##13##Small\";17;2;0;0;1;0;;;;";
	const char REG = ';';
	cout << "RESOURCE:" << res <<endl;
	cout << "REG:" <<REG <<endl;
	split(res,REG);
	cin.get();
	return 0;
}


vector<string> split(string res,const char reg)
{
	vector<string> v;
	signed int start;
	signed int end = res.find(reg,0);
	v.push_back(res.substr(0,end));
	start = end+1;
	while ((end = res.find(reg,start))>0)
	{
		v.push_back(res.substr(start,end-start));
		start = end+1;
	}
	return v;
}
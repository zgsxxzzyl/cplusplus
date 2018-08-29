#ifndef _RESOLVE_H_
#define _RESOLVE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "model.h"

using namespace std;
int main1();
class ResolveCsv
{
public:
	int inFile(string&);
	int outFile(string&);
private:

	ifstream min_file;
	ofstream mout_file;
	string ms_config_name;
	string ms_config_value;

	vector<DataBase> mv_database;
	vector<Dimensions> mv_dimensions;
	vector<Dimension> mv_dimension;
	vector<ElementsDimension> mv_elements_dimension;
	vector<Cubes> mv_cubes;

	map<int,Dimensions> mp_dimensions;
	map<int,Dimension> mp_dimension;

	void inDatabase(string&);
	void inDimensions(string&);
	void inDimension(string&);
	void inElementsDimension(string&);
	void inCubes(string&);

	int outDatabase(ofstream&,vector<DataBase>&);
	int outDimensions(ofstream&,vector<Dimensions>&);
	int outDimension(ofstream&,vector<Dimension>&);
	int outElementsDimension(ofstream&,vector<ElementsDimension>&);
	int outCubes(ofstream&,vector<Cubes>&);

	vector<string> split(string,const char);
};
#endif
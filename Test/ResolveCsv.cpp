#include "resolvecsv.h";

const char DATABASE[] = "DATABASE";
const char DIMENSIONS[] = "DIMENSIONS";
const char CUBES[] = "CUBES";
const char DIMENSION[] = "DIMENSION";
const char ELEMENTS[] = "ELEMENTS";
const char SEPARATOR = ';';
const int LINE_SIZE = 256;
char mc_line[LINE_SIZE];

int main1()
{
	ResolveCsv rc;
	string res = "database.csv";
	string target = "test.txt";

	try
	{
		rc.inFile(res);
		rc.outFile(target);

		cout << "COMPLETE" <<endl;
	}
	catch(char* e)
	{
		cout << e <<endl;
	};
	cout << "Enter next set of numbers <q to quit>: ";
	cin.get();
	return 0;
}

int ResolveCsv::inFile(string &path)
{
	min_file.open(path);
	if (min_file.is_open())
	{
		string buff;

		while (!min_file.eof())
		{
			if(buff.empty())
			{
				memset(mc_line,0,LINE_SIZE);
				min_file.getline(mc_line,LINE_SIZE);
				buff.clear();
			}
			if(mc_line[0] == '#' || strlen(mc_line) == 0)
			{
				continue;
			}
			else
			{
				if (mc_line[0] == '[')
				{
					string str = mc_line;
					ms_config_name = str.substr(1,str.length()-2);  //remove[]
					if (!strcmp(DATABASE,ms_config_name.c_str()))
					{
						inDatabase(buff);
					}
					else if (!strcmp(DIMENSIONS,ms_config_name.c_str()))
					{
						inDimensions(buff);
					}
					else if (!strcmp(CUBES,ms_config_name.c_str()))
					{
						inCubes(buff);
					}
					else
					{
						vector<string> tmp = split(ms_config_name,' ');
						if (tmp.size()>0)
						{
							if(!tmp[0].compare(DIMENSION))
							{
								inDimension(buff);
							}
							else if (!tmp[0].compare(ELEMENTS)&&!tmp[1].compare(DIMENSION))
							{
								inElementsDimension(buff);
							}
							else
							{
								throw "KEY EXPLAIN ERROR";
							}
						}
					}
				}
			}	
		}
	} 
	else
	{
		throw "The file path does not set";
	}
}

int ResolveCsv::outFile(string &path)
{
	mout_file.open(path);
	outDatabase(mout_file,mv_database);
	outDimensions(mout_file,mv_dimensions);
	outDimension(mout_file,mv_dimension);
	outElementsDimension(mout_file,mv_elements_dimension);
	outCubes(mout_file,mv_cubes);
	return 1;
}

void ResolveCsv::inDatabase(string& buff)
{
	while (!min_file.eof())
	{
		memset(mc_line,0,LINE_SIZE);
		min_file.getline(mc_line,LINE_SIZE);
		if(mc_line[0] == '#' || strlen(mc_line) == 0)
		{
			continue;
		}
		if (mc_line[0] == '[')
		{
			string str = mc_line;
			buff = str.substr(1,str.length()-2);
			return;
		}
		vector<string> args = split(mc_line,SEPARATOR);
		DataBase db;
		db.size_dimensions = atoi(args[0].c_str());
		db.size_cubes = atoi(args[1].c_str());
		db.type = atoi(args[2].c_str());
		mv_database.push_back(db);
	}
}

void ResolveCsv::inDimensions(string& buff)
{
	while (!min_file.eof())
	{
		memset(mc_line,0,LINE_SIZE);
		min_file.getline(mc_line,LINE_SIZE);
		if(mc_line[0] == '#' || strlen(mc_line) == 0)
		{
			continue;
		}
		if (mc_line[0] == '[')
		{
			string str = mc_line;
			buff = str.substr(1,str.length()-2);
			return;
		}
		vector<string> args = split(mc_line,SEPARATOR);
		Dimensions dims;
		dims.id = atoi(args[0].c_str());
		strcpy_s(dims.name,args[1].c_str());
		dims.type = atoi(args[2].c_str());
		mv_dimensions.push_back(dims);
		mp_dimensions.insert(map<int,Dimensions>::value_type(dims.id,dims));
	}
}

void ResolveCsv::inDimension(string& buff)
{
	while (!min_file.eof())
	{
		memset(mc_line,0,LINE_SIZE);
		min_file.getline(mc_line,LINE_SIZE);
		if(mc_line[0] == '#' || strlen(mc_line) == 0)
		{
			continue;
		}
		if (mc_line[0] == '[')
		{
			string str = mc_line;
			buff = str.substr(1,str.length()-2);
			return;
		}

		vector<string> args = split(mc_line,SEPARATOR);
		Dimension dim;
		strcpy(dim.dimension_num,ms_config_name.c_str());
		dim.id = atoi(args[0].c_str());
		strcpy(dim.name,args[1].c_str());
		dim.level = atoi(args[2].c_str());
		dim.indent = atoi(args[3].c_str());
		dim.depth = atoi(args[4].c_str());
		dim.size_elements = atoi(args[5].c_str());
		mv_dimension.push_back(dim);
		mp_dimension.insert(map<int,Dimension>::value_type(dim.id,dim));
	}
}

void ResolveCsv::inElementsDimension(string& buff)
{
	while (!min_file.eof())
	{
		memset(mc_line,0,LINE_SIZE);
		min_file.getline(mc_line,LINE_SIZE);
		if(mc_line[0] == '#' || strlen(mc_line) == 0)
		{
			continue;
		}
		if (mc_line[0] == '[')
		{
			string str = mc_line;
			buff = str.substr(1,str.length()-2);
			return;
		}

		vector<string> args = split(mc_line,SEPARATOR);
		ElementsDimension ed;
		strcpy(ed.elements_dimension_num,ms_config_name.c_str());
		ed.id = atoi(args[0].c_str());
		strcpy(ed.name,args[1].c_str());
		strcpy(ed.position,args[2].c_str());
		ed.type = atoi(args[3].c_str());
		ed.string_consoldidation = atoi(args[4].c_str());
		ed.level = atoi(args[5].c_str());
		ed.indent = atoi(args[6].c_str());
		ed.depth = atoi(args[7].c_str());
		ed.parents = atoi(args[8].c_str());
		ed.children = atoi(args[9].c_str());
		ed.children_weight = atoi(args[10].c_str());
		mv_elements_dimension.push_back(ed);
	}
}

void ResolveCsv::inCubes(string& buff)
{
	while (!min_file.eof())
	{
		memset(mc_line,0,LINE_SIZE);
		min_file.getline(mc_line,LINE_SIZE);
		if(mc_line[0] == '#' || strlen(mc_line) == 0)
		{
			continue;
		}

		vector<string> args = split(mc_line,SEPARATOR);
		if( args.size() == 1)
		{
			cout << args.size() <<endl;
			cout << mc_line <<endl;
		}

		Cubes cubs;
		cubs.id = atoi(args[0].c_str());
		strcpy_s(cubs.name,args[1].c_str());
		strcpy_s(cubs.dimensions,args[2].c_str());
		cubs.type = atoi(args[3].c_str());
		cubs.deletable = atoi(args[4].c_str());
		cubs.renamable = atoi(args[5].c_str());
		mv_cubes.push_back(cubs);
	}
}

int ResolveCsv::outDatabase(ofstream& out,vector<DataBase>& vdatabase)
{
	out << "[DATABASE]"<<endl;
	for(int i=0;i<vdatabase.size();i++)
	{
		out << "SIZE_DIMENSIONS:" << vdatabase[i].size_dimensions << " ";
		out << "SIZE_CUBES:" << vdatabase[i].size_cubes << " ";
		out << "TYPE:" << vdatabase[i].type<<endl;
	}
	return 1;
}

int ResolveCsv::outDimensions(ofstream& out,vector<Dimensions>& vdimensions)
{
	out << "[DIMENSIONS]" <<endl;
	for(int i=0;i<vdimensions.size();i++)
	{
		out << "ID:" <<vdimensions[i].id << " ";
		out << "NAME:" << vdimensions[i].name << " ";
		out << "TYPE:" << vdimensions[i].type <<endl;
	}
	return 1;
}

int ResolveCsv::outDimension(ofstream& out,vector<Dimension>& vdimension)
{
	for(int i=0;i<vdimension.size();i++)
	{
		out << "["<< vdimension[i].dimension_num << "] name: " << mp_dimensions[vdimension[i].id].name <<endl;
		out << "ID:" << vdimension[i].id << " ";
		out << "NAME:" << vdimension[i].name << " ";
		out << "LEVEL:" << vdimension[i].level << " ";
		out << "INDENT:" << vdimension[i].indent << " ";
		out << "DEPTH:" << vdimension[i].depth << " ";
		out << "SIZE_ELEMENTS:" << vdimension[i].size_elements << endl;
		
	}
	return 1;
}

int ResolveCsv::outElementsDimension(ofstream& out,vector<ElementsDimension>& velementsdimension)
{
	for(int i=0;i<velementsdimension.size();i++)
	{
		out << "["<< velementsdimension[i].elements_dimension_num << "]" <<endl;
		out << "ID:" << velementsdimension[i].id << " ";
		out << "NAME:" << velementsdimension[i].name << " ";
		out << "POSITION:" << velementsdimension[i].position << " ";
		out << "TYPE:" << velementsdimension[i].type << " ";
		out << "STRING_CONSOLIDATION:" << velementsdimension[i].string_consoldidation << " ";
		out << "LEVEL:" << velementsdimension[i].level << " ";
		out << "INDENT:" << velementsdimension[i].indent << " ";
		out << "DEPTH:" << velementsdimension[i].depth << " ";
		out << "PARENTS:" << velementsdimension[i].parents << " ";
		out << "CHILDREN:" << velementsdimension[i].children << " ";
		out << "CHILDREN_WEIGHT:" << velementsdimension[i].children_weight << endl;
	}
	return 1;
}

int ResolveCsv::outCubes(ofstream& out,vector<Cubes>& vcubes)
{
	out << "[CUBES]" <<endl;
	string tmp;
	vector<string> vtmp;
	for(int i=0;i<vcubes.size();i++)
	{
		out << "ID:" << vcubes[i].id << " ";
		out << "NAME:" << vcubes[i].name << " ";

		out << "DIMENSIONS:";
		tmp = vcubes[i].dimensions;
		vtmp = split(tmp,',');
		for (int i = 0; i< vtmp.size(); i++)
		{
			out << "["<<vtmp[i] <<":"<< mp_dimensions[atoi(vtmp[i].c_str())].name << "]";
		}
		out << endl;
		out << "TYPE:" << vcubes[i].type << " ";
		out << "DELETABLE:" << vcubes[i].deletable << " ";
		out << "RENAMABLE:" << vcubes[i].renamable << endl;
	}
	return 1;
}

vector<string> ResolveCsv::split(string res,const char reg)
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
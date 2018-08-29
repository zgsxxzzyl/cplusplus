#ifndef _MODEL_H_
#define _MODEL_H_
//SIZE_DIMENSIONS;SIZE_CUBES;TYPE

struct DataBase
{
	int size_dimensions;
	int size_cubes;
	int type;
};
//ID;NAME;TYPE;...
struct Dimensions
{
	int id;
	char name[1000];
	int type;
};

//ID;NAME,LEVEL,INDENT,DEPTH,SIZE_ELEMENTS; 
struct Dimension
{
	char dimension_num[50];
	int id;
	char name[50];
	int level;
	int indent;
	int depth;
	int size_elements;

};

//ID;NAME,POSITION,TYPE,STRING_CONSOLIDATION,LEVEL,INDENT,DEPTH,PARENTS,CHILDREN,CHILDREN_WEIGHT; 
struct ElementsDimension
{
	char elements_dimension_num[50];
	int id;
	char name[50];
	char position[50];
	int type;
	int string_consoldidation;
	int level;
	int indent;
	int depth;
	int parents;
	int children;
	int children_weight;
};
//ID;NAME;DIMENSIONS;TYPE;DELETABLE;RENAMABLE;...
struct Cubes
{
	int id;
	char name[1000];
	char dimensions[1000];
	int type;
	int deletable;
	int renamable;
};
#endif
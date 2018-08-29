//SIZE_DIMENSIONS;SIZE_CUBES;TYPE
struct database
{
	int size_dimensions;
	int size_cubes;
	int type;
};
//ID;NAME;TYPE;...
struct dimensions
{
	int id;
	char* name;
	int type;
};

//ID;NAME,LEVEL,INDENT,DEPTH,SIZE_ELEMENTS; 
struct dimension
{
	int id;
	char name[50];
	int level;
	int indent;
	int depth;
	int siez_elements;
};
//ID;NAME,POSITION,TYPE,STRING_CONSOLIDATION,LEVEL,INDENT,DEPTH,PARENTS,CHILDREN,CHILDREN_WEIGHT; 
struct elements_dimension
{
	int id;
	char name[50];
	char position[50];
	int type;
	int string_consoldidation;
	int level;
	int indent;
	int depth;
	int children;
	int children_weight;
};
//ID;NAME;DIMENSIONS;TYPE;DELETABLE;RENAMABLE;...
struct cubes
{
	int id;
	char name[50];
	int dimensions;
	int type;
	int deletable;
	int renamable;
};
/* fread example: read an entire file */

#include <stdio.h>
#include <stdlib.h>
using namespace std;

int demo() {
	FILE * pFile;
	long lSize;
	char * buffer;
	size_t result;

	fopen_s(&pFile, "E:\\IMG\\CafeToolbar¾ÉÍ¼±ê\\CafeToolbarµÚÒ»°æ\\action_clear_all_filters.png", "rb");
	if (pFile == NULL) { fputs("File error", stderr); exit(1); }

	// obtain file size:
	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);

	// allocate memory to contain the whole file:
	buffer = (char*)malloc(sizeof(char)*lSize);
	if (buffer == NULL) { fputs("Memory error", stderr); exit(2); }

	// copy the file into the buffer:
	result = fread(buffer, 1, lSize, pFile);
	if (result != lSize) { fputs("Reading error", stderr); exit(3); }

	/* the whole file is now loaded in the memory buffer. */

	// terminate
	fclose(pFile);
	free(buffer);
	return 0;
}
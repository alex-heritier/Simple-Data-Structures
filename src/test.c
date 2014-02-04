
#include <stdio.h>

#include "data_structures.h"

int main(int argc, char *argv[])
{
	struct array *arr = array_create(10, sizeof(char *));
	printf("%lu\n", sizeof(*arr));
	
	return 0;
}
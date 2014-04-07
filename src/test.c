
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "data_structures.h"

int compare(const void *adding, const void *in_tree)
{
	return strcmp((char *)adding, (char *)in_tree);
}

int print_tree(const void *data)
{
	puts((char *)data);
	return 1;
}

int main(int argc, char *argv[])
{
	struct tree *tr = tree_create();
	char *data = malloc(11);
	char *data2 = malloc(12);
	char *yo = "Hello ";
	char *lo = "world!";
	
	sprintf(data, "first_data");
	sprintf(data2, "second_data");
	
	tree_add(tr, data, compare);
	tree_add(tr, data2, compare);
	tree_add(tr, yo, compare);
	tree_add(tr, lo, compare);
	
	tree_map(tr, print_tree);
	
	tree_destroy(tr);
	
	return 0;
}

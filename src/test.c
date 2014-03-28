
#include <stdio.h>

#include "data_structures.h"

int action(void *const data)
{
	printf("%d\n", *(int *)data);
	return 1;
} 

int main(int argc, char *argv[])
{
	struct array *arr = array_create(3);
	int *i = malloc(sizeof(int));
	*i = 666;
	array_add(arr, i);
	printf("buffer_ammount: %d\n", arr->buffer_amount);
	printf("%p\n", arr->data);
	printf("%d\n", *(int *)array_get(arr, 0));
	
	free(i);
	i = malloc(sizeof(int));
	*i = 222;
	int *j = malloc(sizeof(int));
	*j = 101;
	array_set(arr, 0, i);
	array_add(arr, j);
	array_map(arr, action);
	
	
	return 0;
}
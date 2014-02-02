
#include <stdio.h>

#include "list.h"

int action(const void *data)
{
	static char i = '0';
	*(int *)data = i;
	i++;
	return *(int *)data;
}

int main(int argc, char *argv[])
{
	Node *list = list_create();
	for (int i = 0; i < 100; i++) {
		int *i_ptr = (int *)malloc(sizeof(int));
		*i_ptr = i;
		list_add(list, i_ptr);
	}
	list_show(list);
	printf("list has %d elements in it.\n", list_size(list));
	list_foreach(list, action);
	list_show(list);
	
	list_destroy(list);
	
	return 0;
}
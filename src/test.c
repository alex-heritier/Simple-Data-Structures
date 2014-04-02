
#include <stdio.h>
#include <assert.h>

#include "data_structures.h"

int action(void *const data)
{
	printf("%s", (char *)data);
	return 1;
}

int main(int argc, char *argv[])
{
	struct map *m = map_create(3);
	char *key2 = "yolo";
	char *key3 = "swag";
	char *key4 = "lel";
	map_add(m, key2, "Hello");
	map_add(m, key3, " ");
	map_add(m, key4, "meng!\n");
	map_map(m, action);
	
	map_set(m, key4, "world!\n");
	map_map(m, action);
	
	return 0;
}
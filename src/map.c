
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "map.h"
#include "array.h"

struct map *map_create(const int amount)
{
	struct map *m = malloc(sizeof(struct map));
	m->keys = array_create(amount);
	m->data = array_create(amount);
	
	return m;
}

int map_destroy(struct map *m)
{
	array_destroy(m->keys);
	array_destroy(m->data);
	free(m);
	
	return 1;
}

int	map_fulldestroy(struct map *m)
{
	array_fulldestroy(m->keys);
	array_fulldestroy(m->data);
	free(m);
	
	return 1;
}

int map_haskey(const struct map *m, const char *key)
{
	assert(m && key);
	
	void **curr = m->keys->data;
	for (int i = 0; i < array_size(m->keys); ++i) {
		char *curr_key = *(char **)curr;
		if (strcmp(curr_key, key) == 0) return 1;
		curr++;
	}
	return 0;
}

int map_add(struct map *m, const char *key, const void *data)
{
	assert(m && key && data);
	
	if (map_haskey(m, key)) return 0;
	
	int ret1 = array_add(m->keys, key);
	int ret2 = array_add(m->data, data);
	
	return ret1 && ret2;
}

int map_size(const struct map *m)
{
	return array_size(m->keys);
}

void *map_get(const struct map *m, const char *key)
{
	assert(m && key);
	
	int index = array_indexof(m->keys, key, strlen(key));
	return array_get(m->data, index);
}

int	map_set(struct map *m, const char *key, const void *data)
{
	assert(m && key && data);
	
	int index = array_indexof(m->keys, key, strlen(key));
	return array_set(m->data, index, data);
}

int	map_setnull(struct map *m, const char *key)
{
	assert(m && key);
	
	int index = array_indexof(m->keys, key, strlen(key));
	return array_setnull(m->data, index);
}

int map_map(struct map *m, int (action)(void *const data))
{
	return array_map(m->data, action);
}

void *map_remove(struct map *m, const char *key)
{
	assert(m && key);
	
	int index = array_indexof(m->keys, key, strlen(key));
	array_remove(m->keys, index);
	return array_remove(m->data, index);
}

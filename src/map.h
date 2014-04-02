
#ifndef MAP_H
#define MAP_H

#include "array.h"

struct map {
	struct array *data;
	struct array *keys;
};

struct map *	map_create(const int amount);
int 			map_destroy(struct map *m);
int				map_fulldestroy(struct map *m);
int				map_haskey(const struct map *m, const char *key);
int 			map_add(struct map *m, const char *key, const void *data);
int 			map_size(const struct map *m);
void *			map_get(const struct map *m, const char *key);
int				map_set(struct map *m, const char *key, const void *data);
int				map_setnull(struct map *m, const char *key);
int 			map_map(struct map *m, int (action)(void *const data));
void *			map_remove(struct map *m, const char *key);

#endif
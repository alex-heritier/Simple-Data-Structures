
#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

struct array *	queue_create(const int amount);
int 			queue_destroy(struct array *q);
int				queue_fulldestroy(struct array *q);
int 			queue_push(struct array *q, const void *data);
int 			queue_size(const struct array *q);
void *			queue_pop(struct array *q);
void *			queue_peek(const struct array *q);
int				queue_swap(struct array *q, const void *data);
int 			queue_map(struct array *q, int (action)(void *const data));

#endif
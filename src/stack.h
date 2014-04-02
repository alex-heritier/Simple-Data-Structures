
#ifndef STACK_H
#define STACK_H

#include <stddef.h>

//#include "array.h"

struct array *	stack_create(const int amount);
int 			stack_destroy(struct array *st);
int				stack_fulldestroy(struct array *st);
int 			stack_push(struct array *st, const void *data);
int 			stack_size(const struct array *st);
void *			stack_pop(struct array *st);
void *			stack_peek(const struct array *st);
int				stack_swap(struct array *st, const void *data);
int 			stack_map(struct array *st, int (action)(void *const data));

#endif
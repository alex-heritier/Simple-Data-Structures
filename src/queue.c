
#include "queue.h"
#include "array.h"

struct array *queue_create(const int amount)
{
	return array_create(amount);
}

int queue_destroy(struct array *q)
{
	return array_destroy(q);
}

int	queue_fulldestroy(struct array *q)
{
	return array_fulldestroy(q);
}

int queue_push(struct array *q, const void *data)
{
	return array_add(q, data);
}

int queue_size(const struct array *q)
{
	return array_size(q);
}

void *queue_pop(struct array *q)
{
	return array_remove(q, 0);
}

void *queue_peek(const struct array *q)
{
	return array_get(q, 0);
}

int queue_swap(struct array *q, const void *data)
{
	return array_set(q, 0, data);
}

int queue_map(struct array *q, int (action)(void *const data))
{
	return array_map(q, action);
}
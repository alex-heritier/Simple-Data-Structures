
#include "stack.h"
#include "array.h"

struct array *stack_create(const int amount)
{
	return array_create(amount);
}

int stack_destroy(struct array *st)
{
	return array_destroy(st);
}

int	stack_fulldestroy(struct array *st)
{
	return array_fulldestroy(st);
}

int stack_push(struct array *st, const void *data)
{
	return array_add(st, data);
}

int stack_size(const struct array *st)
{
	return array_size(st);
}

void *stack_pop(struct array *st)
{
	int last_index = array_size(st) - 1;
	void *return_value = array_get(st, last_index);
	
	array_setnull(st, last_index);
	st->data_amount--;
	return return_value;
}

void *stack_peek(const struct array *st)
{
	int last_index = stack_size(st) - 1;
	void *return_value = array_get(st, last_index);
	
	return return_value;
}

int	stack_swap(struct array *st, const void *data)
{
	return array_set(st, array_size(st) - 1, data);
}

int stack_map(struct array *st, int (action)(void *const data))
{
	return array_map(st, action);
}
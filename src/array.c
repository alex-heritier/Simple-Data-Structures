
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "array.h"

static int pow(int num, int pow)
{
	assert(pow >= 0);
	int ret = 1;
	for (int i = 0; i < pow; i++) {
		ret *= num;
	}
	return ret;
}

static int round_to_nearest_power(int num, int base)
{
	int exp = 0;
	while (pow(base, exp) <= num) {
		exp++;
	}
	return pow(base, exp);
}

//	struct array *array_create(int size);
//	info: allocates memory for a struct array of at least size
//	return: returns pointer to newly allocated struct array memory
	
struct array *array_create(int amount, int data_size)
{
	struct array *arr = (struct array *)calloc(1, sizeof(struct array));
	arr->data_amount = amount;
	arr->data_size = data_size;
	arr->buffer_size = round_to_nearest_power(amount, 2);
	arr->data = calloc(arr->buffer_size, data_size);
	return arr;
}
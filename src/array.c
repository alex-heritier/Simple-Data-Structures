
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

static void fill_array(void **arr1, void **arr2, int amount)
{
	for (int i = 0; i < amount; i++) {
		arr1[i] = arr2[i];
	}
}

int array_setnull(struct array *arr, const int index)
{
	assert(arr);
	
	if (index < 0 || index >= arr->data_amount) {
		return 0;
	}
	
	void **curr = arr->data;
	for (int i = 0; i < index; ++i) {
		curr++;
	}
	*curr = 0;
	return 1;
}

//	struct array *array_create(int size);
//	info: allocates memory for a struct array of at least size
//	return: returns pointer to newly allocated struct array memory
	
struct array *array_create(const int amount)
{
	struct array *arr = calloc(1, sizeof(struct array));
	arr->data_amount = 0;
	arr->buffer_amount = round_to_nearest_power(amount, 2);	//round to nearest
	arr->data = calloc(arr->buffer_amount, sizeof(void *));	//power of 2
	
	return arr;
}

/*
int 			array_destroy(struct array *arr);
int				array_fulldestroy(struct array *arr);
int 			array_add(struct array *arr, const void *data);
int 			array_size(const struct array *arr);
void *			array_get(struct array *arr, int index);
int				array_set(struct array *arr, int index, void *data);
int 			array_map(struct array *arr, int (action)(void *const data));
*/

//frees up the array

int array_destroy(struct array *arr)
{
	assert(arr);
	
	free(arr);
	
	return 1;
}

//frees up the data in the array and then the array itself

int array_fulldestroy(struct array *arr)
{
	assert(arr);
	
	void **curr = arr->data;
	for (int i = 0; i < arr->data_amount; i++) {
		free(curr[i]);
	}
	free(arr->data);
	free(arr);
	
	return 1;
}

int array_add(struct array *arr, const void *data)
{
	assert(arr && data && "Error: array_add bad data");
	
	if (arr->data_amount >= arr->buffer_amount) {
		//allocate new larger array and copy over existing array
		void *new_array = calloc(2 * arr->buffer_amount, sizeof(void *));
		if (!new_array) return 0;
		fill_array(new_array, arr->data, arr->buffer_amount);
		free(arr->data);
		arr->data = new_array;
		arr->buffer_amount *= 2;
	}
	arr->data[arr->data_amount] = (void *)data;
	arr->data_amount++;
	
	return 1;
}

int array_size(const struct array *arr)
{
	assert(arr);
	
	return arr->data_amount;
}

int	array_indexof(const struct array *arr, const void *data, const int size)
{
	assert(arr && data);
	
	void **curr = arr->data;
	for (int i = 0; i < array_size(arr); ++i) {
		int is_equal = memcmp(*curr, data, size);
		if (is_equal == 0) return i;
		curr++;
	}
	return -1;
}

void *array_get(const struct array *arr, const int index)
{
	assert(arr);
	
	if (index < 0 || index >= arr->data_amount) {
		return NULL;
	}
	
	void **curr = arr->data;
	for (int i = 0; i < index; ++i) {
		curr++;
	}
	return *curr;
}

int	array_set(struct array *arr, const int index, const void *data)
{
	assert(arr && data);
	
	if (index < 0 || index >= arr->data_amount) {
		return 0;
	}
	
	void **curr = arr->data;
	for (int i = 0; i < index; ++i) {
		curr++;
	}
	*curr = (void *)data;
	return 1;
}

int array_map(struct array *arr, int (action)(void *const data))
{
	assert(arr && action);
	
	void **curr = arr->data;
	for (int i = 0; i < arr->data_amount; ++i) {
		action(*curr);
		curr++;
	}
	return 1;
}

void *array_remove(struct array *arr, const int index)
{
	assert(arr);
	
	if (index < 0 || index >= arr->data_amount) {
		return 0;
	}
	
	void *return_value = 0;
	void **curr = arr->data;
	for (int i = 0; i < index; ++i) {	// go to index
		curr++;
	}
	// curr is now the index to delete
	return_value = *curr;
	for (int i = index; i < arr->data_amount; ++i) {
		*curr = *(curr + 1);
		curr++;
	}
	array_setnull(arr, arr->data_amount - 1);
	arr->data_amount--;
	
	return return_value;
}

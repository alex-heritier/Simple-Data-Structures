
#ifndef ARRAY_H
#define ARRAY_H

struct array {
	void **	data;
	int		data_amount;	//number of elements in array
	int 	buffer_amount;	//size of allocated array
};

struct array *	array_create(const int amount);
int 			array_destroy(struct array *arr);
int				array_fulldestroy(struct array *arr);
int 			array_add(struct array *arr, const void *data);
int 			array_size(const struct array *arr);
void *			array_get(const struct array *arr, const int index);
int				array_set(struct array *arr, const int index, const void *data);
int 			array_map(struct array *arr, int (action)(void *const data));

#endif
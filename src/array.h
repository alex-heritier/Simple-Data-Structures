
#ifndef ARRAY_H
#define ARRAY_H

struct array {
	void *	data;
	int		data_amount;
	int 	data_size;
	int 	buffer_size;
};

struct array *	array_create(int amount, int data_size);
int 			array_destroy(struct array *arr);
int				array_fulldestroy(struct array *arr);
int 			array_add(struct array *arr, const void *data);
int 			array_size(const struct array *arr);
void *			array_get(struct array *arr, int index);
int				array_set(struct array *arr, int index, void *data);
int 			array_map(struct array *arr, int (action)(void *const data));

#endif
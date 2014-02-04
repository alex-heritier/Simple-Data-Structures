/*
	clist - A simple data structure library written in C
    Copyright (C) 2014 Alex Heritier

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

//	struct list *list_create();
//	info: allocates memory for a struct list and returns a pointer to it
//	return: pointer to struct list

struct list *list_create()
{
	struct list *list = calloc(1, sizeof(struct list));
	return list;
}

//	int list_destroy(struct list *list);
//	info: iterates through the list freeing each struct list
//	return: return 1 on success, 0 on failure
	
int list_destroy(struct list *list)
{
	assert(list && "list_destroy received a NULL list");
	struct list *curr = list;
	struct list *next = 0;
	while (curr->data != NULL) {
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(curr);	//free the empty tail struct list
	return 1;
}

//	int list_fulldestroy(struct list *list);
//	info: iterates through the list freeing each struct list and its data
//	return:	return 1 on success, 0 on failure
	
int list_fulldestroy(struct list *list)
{
	assert(list && "list_fulldestroy received a NULL list");
	struct list *curr = list;
	struct list *next = 0;
	while (curr->data != NULL) {
		next = curr->next;
		free(curr);
		free(curr->data);
		curr = next;
	}
	free(curr);	//free the empty tail struct list
	return 1;
}

//	int list_create(struct list *list, void *data);
//	info: 	adds the data parameter to the list and
//			allocates a new empty struct list at the tail
//	return: 0 on struct list allocation fail, 1 on success

int list_add(struct list *list, const void *data)
{
	assert(list && data && "list_add received bad data");
	struct list *curr = list;
	while (curr->data != NULL) curr = curr->next;	//find tail struct list
	
	curr->next = (struct list *)calloc(1, sizeof(struct list));
	if(!curr->next) return 0;	//calloc failed
	curr->data = (void *)data;
	return 1;
}

//	void list_show(struct list *list, char *format);
//	info:	iterates through list and prints each struct list's data field using
//			the given format specifier
//	return: nothing
	
void list_show(const struct list *list)
{
	assert(list && "list_show received a NULL struct list");
	struct list *curr = (struct list *)list;
	while (curr->data != NULL) {
		printf("%s\n", curr->data);
		curr = curr->next;
	}
}

//	int list_size(struct list *list);
//	info: returns the number of non-empty struct lists in the list
//	return: number of elements in list
	
int list_size(const struct list *list)
{
	assert(list);
	struct list *curr = (struct list *)list;
	int i = 0;
	while (curr->data != NULL) {
		i++;
		curr = curr->next;
	}
	return i;
}

//	void *list_get(struct list *list, int index);
//	info: returns the data of the struct list at index
//	return: pointer to data field, NULL on failure
	
void *list_get(struct list *list, int index)
{
	assert(list);
	if (index < 0 || index >= list_size(list)) return NULL;
	
	struct list *curr = list;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->data;
}

//	int list_set(struct list *list, int index, void *data);
//	info: sets the node at index's data to point to the data argument
//	return: 1 on success, 0 if index out of bounds
	
int list_set(struct list *list, int index, void *data)
{
	assert(list && data);
	if (index < 0 || index >= list_size(list)) return 0;
	
	struct list *curr = list;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	curr->data = data;
	return 1;
}

//	int list_map(struct list *list, int (action)(void *data));
//	info: iterates over list, calling action with each element's data
//	return: action's return value

int list_map(struct list *list, int (action)(void *const data))
{
	assert(list && action && "list_map received NULL data");
	struct list *curr = list;
	int rc = 0;
	while (curr->data != NULL) {
		rc = action(curr->data);
		curr = curr->next;
	}
	return rc;
}

//	void *list_toarray(struct list *list);
//	info: copies the list data into an array
//	return: returns a pointer to the array
	
void *list_toarray(const struct list *list, const int elem_size)
{
	assert(list && "list_toarray received a NULL list");
	struct list *curr = (struct list *)list;
	void *array = malloc(elem_size * list_size(list));
	int i = 0;
	while(curr->data != NULL) {
		memcpy(array + i, curr->data, elem_size);
		i += elem_size;
		curr = curr->next;
	}
	return array;
}

//	int list_destroy_node(struct list *list, void *data);
//	info: 	finds the struct list with data field that matches the data argument
//			and frees the struct list
//	return: 1 on success, 0 if struct list not found
	
int list_destroy_node(struct list *list, void *data)
{
	assert(list && data && "list_destroy_struct list received NULL data");
	struct list *curr = list;
	struct list *prev = 0;
	while (curr->data != NULL) {
		if (curr->data == data) {
			if (prev) {
				prev->next = curr->next;
			}	
			free(curr);
			return 1;
		}
		prev = curr;
		curr = curr->next;
	}
	return 0;
}
	


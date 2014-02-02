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

//	Node *list_create();
//	info: allocates memory for a Node and returns a pointer to it
//	return: pointer to Node

Node *list_create()
{
	Node *list = calloc(1, sizeof(Node));
	return list;
}

//	int list_destroy(Node *list);
//	info: iterates through the list freeing each Node
//	return: return 1 on success, 0 on failure
	
int list_destroy(Node *list)
{
	assert(list && "list_destroy received a NULL list");
	Node *curr = list;
	Node *next = 0;
	while (curr->data != NULL) {
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(curr);	//free the empty tail Node
	return 1;
}

//	int list_create(Node *list, void *data);
//	info: 	adds the data parameter to the list and
//			allocates a new empty Node at the tail
//	return: 0 on Node allocation fail, 1 on success

int list_add(Node *list, const void *data)
{
	assert(list && data && "list_add received bad data");
	Node *curr = list;
	while (curr->data != NULL) curr = curr->next;	//find tail Node
	
	curr->next = (Node *)calloc(1, sizeof(Node));
	if(!curr->next) return 0;	//calloc failed
	curr->data = (void *)data;
	return 1;
}

//	void list_show(Node *list, char *format);
//	info:	iterates through list and prints each Node's data field using
//			the given format specifier
//	return: nothing
	
void list_show(const Node *list)
{
	assert(list && "list_show received a NULL Node");
	Node *curr = (Node *)list;
	while (curr->data != NULL) {
		printf("%s\n", curr->data);
		curr = curr->next;
	}
}

//	int list_size(Node *list);
//	info: returns the number of non-empty Nodes in the list
//	return: number of elements in list
	
int list_size(const Node *list)
{
	assert(list);
	Node *curr = (Node *)list;
	int i = 0;
	while (curr->data != NULL) {
		i++;
		curr = curr->next;
	}
	return i;
}

//	int list_foreach(Node *list, int (action)(void *data));
//	info: iterates over list, calling action with each element's data
//	return: action's return value

int list_foreach(Node *list, int (action)(const void *data))
{
	assert(list && action && "list_foreach received NULL data");
	Node *curr = list;
	int rc = 0;
	while (curr->data != NULL) {
		rc = action(curr->data);
		curr = curr->next;
	}
	return rc;
}

//	void *list_array(Node *list);
//	info: copies the list data into an array
//	return: returns a pointer to the array
	
void *list_toarray(const Node *list, const int elem_size)
{
	assert(list && "list_array received a NULL list");
	Node *curr = (Node *)list;
	void *array = malloc(elem_size * list_size(list));
	int i = 0;
	while(curr->data != NULL) {
		memcpy(array + i, curr->data, elem_size);
		i += elem_size;
		curr = curr->next;
	}
	return array;
}


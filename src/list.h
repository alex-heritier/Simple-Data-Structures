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

#ifndef LIST_H
#define LIST_H


#include <stdlib.h>

typedef struct Node {
	struct Node *next;
	void *data;
} Node;

Node *	list_create();
int 	list_destroy(Node *list);
int 	list_add(Node *list, const void *data);
void 	list_show(const Node *list);
int 	list_size(const Node *list);
int 	list_foreach(Node *list, int (action)(const void *data));
void *	list_toarray(const Node *list, const int elem_size);

#endif
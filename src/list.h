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

struct list {
	struct list *	next;
	void *			data;
};

struct list *	list_create();
int 			list_destroy(struct list *list);
int				list_fulldestroy(struct list *list);
int 			list_add(struct list *list, const void *data);
//void 			list_show(const struct list *list);
int 			list_size(const struct list *list);
void *			list_get(struct list *list, int index);
int				list_set(struct list *list, int index, void *data);
int 			list_map(struct list *list, int (action)(void *const data));
void *			list_toarray(const struct list *list, const int elem_size);
int				list_destroy_node(struct list *list, void *data);

#endif
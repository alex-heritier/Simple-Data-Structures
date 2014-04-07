
#ifndef TREE_H
#define TREE_H

struct tree {
	struct tree *parent;
	struct tree *left;
	struct tree *right;
	void *data;
};

struct tree *	tree_create();
int				tree_isempty(struct tree *tr);
int 			tree_destroy(struct tree *tr);
int				tree_fulldestroy(struct tree *tr);
int				tree_has(const struct tree *tr, const void *data, int (compare)(const void *data1, const void *data2));
int 			tree_add(struct tree *tr, const void *data, int (compare)(const void *lh, const void *rh));
int 			tree_size(const struct tree *tr);
int 			tree_map(struct tree *tr, int (action)(void const *data));
int 			tree_map_over_node(struct tree *tr, int (action)(struct tree const *node));

#endif
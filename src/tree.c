
#include <stdlib.h>
#include <assert.h>

#include "tree.h"

struct tree *tree_create()
{
	struct tree *tr = malloc(sizeof(struct tree));
	tr->parent = 0;
	tr->left = 0;
	tr->right = 0;
	tr->data = 0;
	
	return tr;
}

int tree_isempty(struct tree *tr)
{
	assert(tr);
	
	return tr->data == 0;
}

int tree_destroy(struct tree *tr)
{	
	if (tr == 0) return 1;
	
	tree_destroy(tr->left);
	tree_destroy(tr->right);
	free(tr);
	
	return 1;
}

int	tree_fulldestroy(struct tree *tr)
{
	if (tr == 0) return 1;
	
	tree_fulldestroy(tr->left);
	tree_fulldestroy(tr->right);
	free(tr->data);
	free(tr);
	
	return 1;
}

int	tree_has(const struct tree *tr, const void *data, int (compare)(const void *data1, const void *data2))
{
	assert(tr && data && compare);
	
	if (!tr->data) {
		return 0;
	}
	
	int result = compare(data, tr->data);
	if (result > 0) {
		if (tr->right) {
			return tree_has(tr->right, data, compare);
		} else {
			return 0;
		}
	} else if (result == 0) {
		return 1;
	} else {
		if (tr->left) {
			return tree_add(tr->left, data, compare);
		} else {
			return 0;
		}
	}
}

int tree_add(struct tree *tr, const void *data, int (compare)(const void *lh, const void *rh))
{
	assert(tr && data && compare);
	
	if (!tr->data) {
		tr->data = (void *)data;
		return 1;
	}
	
	int result = compare(data, tr->data);
	if (result > 0) {
		if (tr->right) {
			return tree_add(tr->right, data, compare);
		} else {
			tr->right = tree_create();
			tr->right->data = (void *)data;
			tr->right->parent = tr;
			return 1;
		}
	} else if (result == 0) {
		return 0;
	} else {
		if (tr->left) {
			return tree_add(tr->left, data, compare);
		} else {
			tr->left = tree_create();
			tr->left->data = (void *)data;
			tr->right->parent = tr;
			return 1;
		}
	}
}

int tree_size(const struct tree *tr)
{
	if (!tr) {
		return 0;
	} else if (!tr->data) {
		return 0;
	} else {
		return 1 + tree_size(tr->left) + tree_size(tr->right);
	}
}

int tree_map(struct tree *tr, int (action)(void const *data))
{
	assert(action);
	if (!tr) return 0;
	
	return tree_map(tr->left, action)
		+ action(tr->data)
		+ tree_map(tr->right, action);
}

int tree_map_over_node(struct tree *tr, int (action)(struct tree const *node))
{
	assert(action);
	if (!tr) return 0;
	
	return tree_map_over_node(tr->left, action)
		+ action(tr)
		+ tree_map_over_node(tr->right, action);
}

#include "binary_trees.h"

/**
 * bst_search - Search for a value in a binary search tree
 * @tree: Pointer to the root of the tree
 * @value: The value to be found
 *
 * Return: The node with the value if found or the parent node to where
 *		it should be inserted or (NULL) if tree is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *t = (bst_t *) (long int) tree;

	if (!t)
		return (NULL);

	if (t->n == value)
		return (t);

	if (t->n > value)
		return (bst_search(t->left, value));
	return (bst_search(t->right, value));
}

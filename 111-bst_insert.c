#include "binary_trees.h"

/**
 * bst_find - Search a bst for a value
 * @tree: Pointer to the root of the tree
 * @value: The value to be found
 *
 * Return: The node with the value if found or the parent node to where
 *		it should be inserted or (NULL) if tree is NULL
 */
bst_t *bst_find(bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (tree->n == value || (!tree->left && !tree->right))
		return (tree);

	if (tree->n > value)
	{
		if (!tree->left)
			return (tree);
		return (bst_find(tree->left, value));
	}

	if (!tree->right)
		return (tree);
	return (bst_find(tree->right, value));
}

/**
 * bst_insert - Inserts a new value in a Binary Search Tree
 * @tree: Pointer to the address of the root of the tree
 * @value: The value to be inserted
 *
 * Return: The new node address on success or (NULL) otherwise
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *parent;

	if (!tree)
		return (0);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	parent = bst_find(*tree, value);
	if (parent->n == value)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (parent->n > value)
		parent->left = new;
	else
		parent->right = new;

	return (new);
}

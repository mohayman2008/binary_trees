#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle node of a node in a binary tree
 * @node: Pointer to a binary tree node
 *
 * Return: The uncle node if found or (NULL) otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grand_parent;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	parent = node->parent;
	grand_parent = parent->parent;

	if (grand_parent->left == parent)
		return (grand_parent->right);
	if (grand_parent->right == parent)
		return (grand_parent->left);
	return (NULL);
}

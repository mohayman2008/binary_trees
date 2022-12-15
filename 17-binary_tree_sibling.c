#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling node of a node in a binary tree
 * @node: Pointer to a binary tree node
 *
 * Return: The sibling node if found or (NULL) otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	if (node->parent->right == node)
		return (node->parent->left);
	return (NULL);
}

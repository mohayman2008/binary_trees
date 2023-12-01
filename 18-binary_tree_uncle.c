#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: A pointer to the node to find its uncle
 *
 * Return: A pointer to the uncle node
 *		or NULL if either node, its parent or its parent's parent is NULL
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grand_parent;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	parent = node->parent;
	grand_parent = node->parent->parent;

	if (grand_parent->left == parent)
		return (grand_parent->right);
	return (grand_parent->left);
}

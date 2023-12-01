#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a tree root
 * @node: A pointer to the node to check
 *
 * Return: <1> if the node is a root and <0> if node is NULL or not a root
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);

	return (1);
}

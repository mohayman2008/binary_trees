#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a tree node is a leaf
 * @node: A pointer to the node to check
 *
 * Return: <1> if the node is a leaf and <0> if node is NULL or not a leaf
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);

	return (1);
}

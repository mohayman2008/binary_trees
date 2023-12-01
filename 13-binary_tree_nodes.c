#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes that are not leaves
 *					(at least have 1 child) in a binary tree
 * @tree: A pointer to the root node of the tree to count its non-leaf nodes
 *
 * Return: The number of non-leaf nodes in the tree or <0> if tree is NULL
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (binary_tree_nodes(tree->left)
			+ binary_tree_nodes(tree->right)
			+ 1);
}

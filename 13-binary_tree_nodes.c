#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the parent nodes in a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of parent nodes in the tree or (0) if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (1 + binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
}

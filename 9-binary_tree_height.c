#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: The height of the binary tree or (0) if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_right, h_left;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	h_left = binary_tree_height(tree->left);
	h_right = binary_tree_height(tree->right);

	if (h_left >= h_right)
		return (1 + h_left);
	return (1 + h_right);
}

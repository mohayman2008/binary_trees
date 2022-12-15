#include "binary_trees.h"

/**
 * binary_tree_height_extended - Measures the height of a binary tree
 *				(it consider the leaves as hight extension)
 * @tree: Pointer to the root of the tree
 *
 * Return: The height of the binary tree or (0) if tree is NULL
 */
size_t binary_tree_height_extended(const binary_tree_t *tree)
{
	size_t h_right, h_left;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	h_left = binary_tree_height_extended(tree->left);
	h_right = binary_tree_height_extended(tree->right);

	if (h_left >= h_right)
		return (1 + h_left);
	return (1 + h_right);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root of the tree
 *
 * Return: (1) if the tree is perfect or (0) otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right) &&
		(binary_tree_height_extended(tree->left)
		== binary_tree_height_extended(tree->right))
		);
}

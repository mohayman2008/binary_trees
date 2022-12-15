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
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: The balance factor or (0) if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height_extended(tree->left) -
		binary_tree_height_extended(tree->right));
}

#include "binary_trees.h"

/**
 * get_binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree or <0> if tree is NULL
*/
size_t get_binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	left_h = get_binary_tree_height(tree->left);
	right_h = get_binary_tree_height(tree->right);

	if (left_h > right_h)
		return (left_h + 1);

	return (right_h + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is a perfect tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: <1> if the tree is a perfect tree or <0> if not or if tree is NULL
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_check;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left || !tree->right)
		return (0);

	height_check = (get_binary_tree_height(tree->left)
					== get_binary_tree_height(tree->right));
	return (height_check
			&& binary_tree_is_perfect(tree->left)
			&& binary_tree_is_perfect(tree->right));
}

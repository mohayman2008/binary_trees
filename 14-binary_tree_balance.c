#include "binary_trees.h"

/**
 * binary_tree_nodal_height - Measures the nodal height of a binary tree
 * @tree: A pointer to the root node of the tree to measure its nodal height
 *
 * Return: The nodal height of the tree or <0> if tree is NULL
*/
size_t binary_tree_nodal_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (!tree)
		return (0);

	left_h = binary_tree_nodal_height(tree->left);
	right_h = binary_tree_nodal_height(tree->right);

	if (left_h > right_h)
		return (left_h + 1);

	return (right_h + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree to measure its balance factor
 *
 * Return: The balance factor of the tree or <0> if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return ((int) binary_tree_nodal_height(tree->left)
			- (int) binary_tree_nodal_height(tree->right));
}

#include "binary_trees.h"

/**
 * binary_tree_preorder_gt - Traverse a binary tree through in-order traversal
 *				and check if each node value is greater than certain value
 * @tree: Pointer to the root of the tree
 * @value: The value to compare with
 *
 * Return: (1) in case all the nodes are greater than value and (0) otherwise
 */
int binary_tree_preorder_gt(const binary_tree_t *tree, int value)
{
	if (!tree)
		return (1);

	return ((tree->n > value) &&
		binary_tree_preorder_gt(tree->left, value) &&
		binary_tree_preorder_gt(tree->right, value));
}

/**
 * binary_tree_preorder_lt - Traverse a binary tree through in-order traversal
 *				and check if each node value is less than certain value
 * @tree: Pointer to the root of the tree
 * @value: The value to compare with
 *
 * Return: (1) in case all the nodes are less than value and (0) otherwise
 */
int binary_tree_preorder_lt(const binary_tree_t *tree, int value)
{
	if (!tree)
		return (1);

	return ((tree->n < value) &&
		binary_tree_preorder_lt(tree->left, value) &&
		binary_tree_preorder_lt(tree->right, value));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree
 * @tree: Pointer to the root of the tree
 *
 * Return: (1) if the tree is a binary search tree or (0) otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!binary_tree_preorder_lt(tree->left, tree->n) ||
		!binary_tree_preorder_gt(tree->right, tree->n))
	{
		return (0);
	}

	return (!tree->left || binary_tree_is_bst(tree->left)) &&
		(!tree->right || binary_tree_is_bst(tree->right));
}

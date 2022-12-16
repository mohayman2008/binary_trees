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
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree
 * @tree: Pointer to the root of the tree
 *
 * Return: (1) if the tree is an AVL tree or (0) otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	ssize_t diff;

	if (!tree)
		return (0);

	if (!binary_tree_preorder_lt(tree->left, tree->n) ||
		!binary_tree_preorder_gt(tree->right, tree->n))
	{
		return (0);
	}

	diff = binary_tree_height_extended(tree->left) -
		binary_tree_height_extended(tree->right);

	if (diff > 1 || diff < -1)
		return (0);

	return ((!tree->left || binary_tree_is_avl(tree->left)) &&
		(!tree->right || binary_tree_is_avl(tree->right)));
}

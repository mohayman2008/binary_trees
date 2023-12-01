#include "binary_trees.h"

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: The size of the tree or (0) if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * is_complete - Checks if a tree is complete or not
 * @tree: Pointer to the root of the tree
 * @idx: Index of the checked sub_tree (going top-down then left-right)
 * @nodes_num: Number of nodes in the main tree
 *
 * Return: (1) if the tree is complete or (0) otherwise
 */
int is_complete(const binary_tree_t *tree, size_t idx, size_t nodes_num)
{
	if (!tree)
		return (1);

	if (idx >= nodes_num)
		return (0);

	return (is_complete(tree->left, idx * 2 + 1, nodes_num) &&
		is_complete(tree->right, idx * 2 + 2, nodes_num));
}

/**
 * are_little_children - Checks if all children values in a binary tree are
 *			less than their parents values
 * @tree: Pointer to the root of the tree
 *
 * Return: (1) if all parents values are greater than values of their children
 *	or (0) otherwise
 */
int are_little_children(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->parent && tree->parent->n < tree->n)
		return (0);

	return (are_little_children(tree->left) &&
		are_little_children(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap tree
 * @tree: Pointer to the root of the tree
 *
 * Return: (1) if the tree is a max heap tree or (0) otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!is_complete(tree, 0, tree_size(tree)))
		return (0);

	return (are_little_children(tree));
}

#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is a full tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: <1> if the tree is a full tree or <0> if not or if tree is NULL
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left || !tree->right)
		return (0);

	return (binary_tree_is_full(tree->left)
			&& binary_tree_is_full(tree->right));
}

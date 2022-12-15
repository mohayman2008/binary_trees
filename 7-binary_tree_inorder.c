#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverse a binary tree through in-order traversal
 * @tree: Pointer to the root of the tree
 * @func: Function to be called for the value of each node in the tree
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}

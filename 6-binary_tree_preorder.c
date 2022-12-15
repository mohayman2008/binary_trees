#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverse a binary tree through pre-order traversal
 * @tree: Pointer to the root of the tree
 * @func: Function to be called for the value of each node in the tree
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}

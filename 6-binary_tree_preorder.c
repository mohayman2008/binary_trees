#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverse a binary tree pre-orderly
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node, The value of
 *		the node is passed as a parameter to this function
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}

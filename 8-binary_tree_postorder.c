#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree post-orderly
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node, The value of
 *		the node is passed as a parameter to this function
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}

#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotate a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Pointer to the new root or NULL if tree is NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree)
		return (NULL);

	if (!tree->left)
		return (tree);

	new_root = tree->left;
	new_root->parent = tree->parent;
	if (new_root->parent)
	{
		if (new_root->parent->left == tree)
			new_root->parent->left = new_root;
		else if (new_root->parent->right == tree)
			new_root->parent->right = new_root;
	}
	tree->left = new_root->right;
	if (tree->left)
		tree->left->parent = tree;
	new_root->right = tree;
	tree->parent = new_root;

	return (new_root);
}

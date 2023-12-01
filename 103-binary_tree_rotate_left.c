#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotate a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Pointer to the new root or NULL if tree is NULL
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree)
		return (NULL);

	if (!tree->right)
		return (tree);

	new_root = tree->right;
	new_root->parent = tree->parent;
	if (new_root->parent)
	{
		if (new_root->parent->left == tree)
			new_root->parent->left = new_root;
		else if (new_root->parent->right == tree)
			new_root->parent->right = new_root;
	}
	tree->right = new_root->left;
	if (tree->right)
		tree->right->parent = tree;
	new_root->left = tree;
	tree->parent = new_root;

	return (new_root);
}

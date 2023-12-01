#include "binary_trees.h"

/**
 * bst_search2 - Search for a value in a binary search tree
 * @tree: Pointer to the root of the tree
 * @value: The value to be found
 *
 * Return: The node with the value if found or the parent node to where
 *		it should be inserted or (NULL) if tree is NULL
 */
bst_t *bst_search2(const bst_t *tree, int value)
{
	bst_t *t = (bst_t *) (long int) tree;

	if (!t)
		return (NULL);

	if (t->n == value)
		return (t);

	if (t->n > value)
		return (bst_search2(t->left, value));
	return (bst_search2(t->right, value));
}

/**
 * bst_remove - Removes a node from a binary search tree
 * @root: Pointer to the root of the tree
 * @value: The value to remove its corresponding node
 *
 * Return: The root node or (NULL) if tree is NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *successor, *new_root = root;

	if (!root)
		return (NULL);

	node = bst_search2(root, value);
	if (!node)
		return (root);
	if (!node->right)
		successor = node->left;
	else if (!node->left)
		successor = node->right;
	else
	{/* Find the smallest node in the right tree */
		successor = node->right;
		while (successor->left)
			successor = successor->left;
		if (successor != node->right)
		{
			successor->parent->left = successor->right;
			if (successor->right)
				successor->right->parent = successor->parent;
			node->right->parent = successor;
			successor->right = node->right;
		}
		successor->left = node->left,
		node->left->parent = successor;
	}

	if (successor)
		successor->parent = node->parent;
	if (!node->parent)
		new_root = successor;
	else if (node->parent->right == node)
		node->parent->right = successor;
	else
		node->parent->left = successor;

	free(node);
	return (new_root);
}

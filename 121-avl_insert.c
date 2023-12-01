#include "binary_trees.h"

/**
 * avl_find - Search an avl tree for a value
 * @tree: Pointer to the root of the tree
 * @value: The value to be found
 *
 * Return: The node with the value if found or the parent node to where
 *		it should be inserted or (NULL) if tree is NULL
 */
avl_t *avl_find(avl_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (tree->n == value || (!tree->left && !tree->right))
		return (tree);

	if (tree->n > value)
	{
		if (!tree->left)
			return (tree);
		return (avl_find(tree->left, value));
	}

	if (!tree->right)
		return (tree);
	return (avl_find(tree->right, value));
}

/**
 * balance_avl_up - Balancing an avl tree recursively up
 * @tree: Pointer to the address of the root of the tree
 * @node: Pointer to the starting node
 */
void balance_avl_up(avl_t **tree, avl_t *node)
{
	avl_t *parent;
	int balance;

	if (!tree || !*tree || !node || !node->parent)
		return;

	parent = node->parent;
	balance = binary_tree_balance(parent);
	if (balance > 1)
	{
		if (binary_tree_balance(parent->left) < 0)
			binary_tree_rotate_left(parent->left);
		parent = binary_tree_rotate_right(parent);
	}
	else if (balance < -1)
	{
		if (binary_tree_balance(parent->right) > 0)
			binary_tree_rotate_right(parent->right);
		parent = binary_tree_rotate_left(parent);
	}

	if (!parent->parent)
		*tree = parent;

	balance_avl_up(tree, parent);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Pointer to the address of the root of the tree
 * @value: The value to be inserted
 *
 * Return: The new node address on success or (NULL) otherwise
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	bst_t *new, *parent;

	if (!tree)
		return (0);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	parent = avl_find(*tree, value);
	if (parent->n == value)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (parent->n > value)
		parent->left = new;
	else
		parent->right = new;

	balance_avl_up(tree, new);

	return (new);
}

#include "binary_trees.h"

/**
 * avl_search - Search for a value in an AVL tree
 * @tree: Pointer to the root of the tree
 * @value: The value to be found
 *
 * Return: The node with the value if found or (NULL) otherwise
 */
avl_t *avl_search(const avl_t *tree, int value)
{
	avl_t *t = (avl_t *) (long int) tree;

	if (!t)
		return (NULL);

	if (t->n == value)
		return (t);

	if (t->n > value)
		return (avl_search(t->left, value));
	return (avl_search(t->right, value));
}

/**
 * balance_avl_up2 - Balancing an avl tree recursively up
 * @tree: Pointer to the address of the root of the tree
 * @node: Pointer to the starting node
 */
void balance_avl_up2(avl_t **tree, avl_t *node)
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

	balance_avl_up2(tree, parent);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root of the tree
 * @value: The value to remove its corresponding node
 *
 * Return: The root node or (NULL) if tree is NULL
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *successor, *new_root = root;

	if (!root)
		return (NULL);
	node = avl_search(root, value);
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

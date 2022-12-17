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
 * balance_avl_down - Balancing an avl tree recursively down
 * @tree: Pointer to the address of the root of the tree
 */
void balance_avl_down(avl_t **tree)
{
	int balance;

	if (!tree || !*tree)
		return;

	balance_avl_down(&(*tree)->left);
	balance_avl_down(&(*tree)->right);

	balance = binary_tree_balance(*tree);
	if (balance > 1)
	{
		if (binary_tree_balance((*tree)->left) < 0)
			binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1)
	{
		if (binary_tree_balance((*tree)->right) > 0)
			binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
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
	balance_avl_down(&new_root);
	return (new_root);
}

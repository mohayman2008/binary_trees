#include "binary_trees.h"

/**
 * tree_size1 - Measures the size of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: The size of the tree or (0) if tree is NULL
 */
size_t tree_size1(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size1(tree->left) + tree_size1(tree->right));
}

/**
 * swap_nodes1 - Swaps two nodes in a binary tree
 * @n1: Pointer to the first node
 * @n2: Pointer to the second node
 */
void swap_nodes1(binary_tree_t *n1, binary_tree_t *n2)
{
	binary_tree_t *left, *right, *parent;

	if (!n1 || !n2)
		return;

	parent = n1->parent;
	left = n1->left;
	right = n1->right;

	n1->left = n2->left == n1 ? n2 : n2->left;
	n1->right = n2->right == n1 ? n2 : n2->right;

	n2->left = left == n2 ? n1 : left;
	n2->right = right == n2 ? n1 : right;

	n1->parent = n2->parent == n1 ? n2 : n2->parent;
	n2->parent = parent == n2 ? n1 : parent;

	if (n1->left)
		n1->left->parent = n1;
	if (n1->right)
		n1->right->parent = n1;
	if (n2->left)
		n2->left->parent = n2;
	if (n2->right)
		n2->right->parent = n2;

	if (n1->parent)
	{
		n1->parent->left = n1->parent->left == n2 ? n1 : n1->parent->left;
		n1->parent->right = n1->parent->right == n2 ? n1 : n1->parent->right;
	}

	if (n2->parent)
	{
		n2->parent->left = n2->parent->left == n1 ? n2 : n2->parent->left;
		n2->parent->right = n2->parent->right == n1 ? n2 : n2->parent->right;
	}
}

/**
 * heapify_down - Moves the root of a max heap tree to a valid position
 *		(The tree must be complete, if not undesired behavior may be resulted)
 * @root: Pointer to the address of the root of the tree
 */
void heapify_down(binary_tree_t **root)
{
	binary_tree_t *tree;

	if (!root || !*root)
		return;

	tree = *root;
	if (!tree->left && !tree->right)
		return;

	if (!tree->right)
	{
		if (tree->left->n > tree->n)
			*root = tree->left;
		else
			return;
	}
	else if (tree->n > tree->right->n && tree->n > tree->left->n)
		return;
	else if (tree->left->n > tree->right->n)
		*root = tree->left;
	else
		*root = tree->right;

	swap_nodes1(tree, *root);

	heapify_down(&((*root)->left));
	heapify_down(&((*root)->right));
}

/**
 * get_heap_last_node - Get the last node in a max heap tree
 * @tree: Pointer to the root of the tree
 * @current_idx: Index of current node in the original tree
 *		(going top-down then left-right)
 * @target: The target index in the tree
 *
 * Return: The address of last node on match or (NULL) otherwise
 */
heap_t *get_heap_last_node(heap_t *tree, size_t current_idx, size_t target)
{
	heap_t *left, *right;

	if (!tree)
		return (NULL);

	if (target == current_idx)
		return (tree);

	if (target < current_idx)
		return (NULL);

	left = get_heap_last_node(tree->left, (current_idx * 2) + 1, target);
	right = get_heap_last_node(tree->right, (current_idx * 2) + 2, target);
	if (left)
		return (left);
	return (right);
}

/**
 * heap_extract - Extract the root of a max heap tree
 *		(The tree must be complete, if not undesired behavior may be resulted)
 * @root: Pointer to the root of the tree
 *
 * Return: The value of the root node or (0) on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *tree;
	int val;

	if (!root || !*root)
		return (0);

	tree = *root;
	val = tree->n;

	*root = get_heap_last_node(*root, 0, tree_size1(*root) - 1);

	swap_nodes1(tree, *root);

	if (tree->parent && tree->parent->left == tree)
		tree->parent->left = NULL;
	else if (tree->parent)
		tree->parent->right = NULL;
	else
		*root = NULL;

	heapify_down(root);
	free(tree);
	return (val);
}

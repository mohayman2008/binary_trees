#include "binary_trees.h"

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: The size of the tree or (0) if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * is_complete - Checks if a tree is complete or not
 * @tree: Pointer to the root of the tree
 * @idx: Index of the checked sub_tree (going top-down then left-right)
 * @nodes_num: Number of nodes in the main tree
 *
 * Return: (1) if the tree is complete or (0) otherwise
 */
int is_complete(const binary_tree_t *tree, size_t idx, size_t nodes_num)
{
	if (!tree)
		return (1);

	if (idx >= nodes_num)
		return (0);

	return (is_complete(tree->left, idx * 2 + 1, nodes_num) &&
		is_complete(tree->right, idx * 2 + 2, nodes_num));
}

/**
 * swap_nodes - Swaps two nodes in a binary tree
 * @n1: Pointer to the first node
 * @n2: Pointer to the second node
 */
void swap_nodes(binary_tree_t *n1, binary_tree_t *n2)
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
 * heapify - Makes a complete binary tree a max heap
 *		(The tree must be complete, if not undesired behavior may be resulted)
 * @root: Pointer to the address of the root of the tree
 */
void heapify(binary_tree_t **root)
{
	binary_tree_t *tree;

	if (!root || !*root)
		return;

	tree = *root;
	if (!tree->left && !tree->right)
		return;

	heapify(&tree->left);
	heapify(&tree->right);

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

	swap_nodes(tree, *root);
}

/**
 * get_heap_next_spot - Get the next vacant spot to insert a new node
 *			in a max heap tree
 * @tree: Pointer to the root of the tree
 * @current_idx: Index of current node in the original tree
 *		(going top-down then left-right)
 * @target: The target index in the tree
 *
 * Return: The address of the parent of the designated spot
 *		or (NULL) on error
 */
heap_t *get_heap_next_spot(heap_t *tree, size_t current_idx, size_t target)
{
	heap_t *left, *right;
	size_t parent_idx;

	if (!tree)
		return (NULL);

	parent_idx = (target - 1) / 2;
	if (parent_idx == current_idx)
		return (tree);

	if (parent_idx < current_idx)
		return (NULL);

	left = get_heap_next_spot(tree->left, (current_idx * 2) + 1, target);
	right = get_heap_next_spot(tree->right, (current_idx * 2) + 2, target);
	if (left)
		return (left);
	return (right);
}

/**
 * heap_insert - Inserts a new value in a max heap tree
 * @root: Pointer to the address of the root of the tree
 * @value: The value to be inserted
 *
 * Return: The new node address on success or (NULL) otherwise
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new;

	if (!root || !is_complete(*root, 0, tree_size(*root)))
		return (NULL);

	parent = get_heap_next_spot(*root, 0, tree_size(*root));

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (!*root)
		*root = new;
	else if (parent->left)
		parent->right = new;
	else
		parent->left = new;

	heapify(root);
	return (new);
}

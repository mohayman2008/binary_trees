#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as a right child of another node
 *			in a binary tree
 * @parent: Pointer to the node to insert the new node in as a right child
 * @value: the value to be represented by the new node
 *
 * Return: Pointer to the new node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = parent->right;
	if (new->right)
		new->right->parent = new;
	new->parent = parent;

	parent->right = new;

	return (new);
}

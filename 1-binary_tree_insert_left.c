#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left child of another node
 *			in a binary tree
 * @parent: Pointer to the node to insert the new node in as a left child
 * @value: the value to be represented by the new node
 *
 * Return: Pointer to the new node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->n = value;
	new->left = parent->left;
	if (new->left)
		new->left->parent = new;
	new->right = NULL;
	new->parent = parent;

	parent->left = new;

	return (new);
}

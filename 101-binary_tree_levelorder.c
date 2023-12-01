#include "binary_trees.h"

/**
 * traverse_level - Traverse a binary tree level in level-order traversal
 * @level_nodes: Array of nodes in the level
 * @func: Function to be called for the value of each node in the tree
 *
 * Return: Dynamically allocated array of the nodes in the next level
 */
binary_tree_t **traverse_level(binary_tree_t **level_nodes, void (*func)(int))
{
	binary_tree_t **nodes_list;
	size_t len = 0, i = 0, j = 0;

	if (!level_nodes || !func)
		return (NULL);

	while (level_nodes[len])
		len++;

	nodes_list = malloc(sizeof(*nodes_list) * (len * 2 + 1));
	if (!nodes_list)
		return (NULL);

	while (i < len)
	{
		func(level_nodes[i]->n);
		if (level_nodes[i]->left)
			nodes_list[j++] = level_nodes[i]->left;
		if (level_nodes[i]->right)
			nodes_list[j++] = level_nodes[i]->right;

		i++;
	}

	nodes_list[j] = NULL;
	free(level_nodes);
	return (nodes_list);
}

/**
 * binary_tree_levelorder - Traverse a binary tree
 *			through level-order traversal
 * @tree: Pointer to the root of the tree
 * @func: Function to be called for the value of each node in the tree
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **nodes_list;

	if (!tree || !func)
		return;

	nodes_list = malloc(sizeof(*nodes_list) * 2);
	if (!nodes_list)
		return;
	nodes_list[0] = (binary_tree_t *) (long int) tree;
	nodes_list[1] = NULL;

	while (*nodes_list)
	{
		nodes_list = traverse_level(nodes_list, func);
		if (!nodes_list)
			return;
	}

	free(nodes_list);
}

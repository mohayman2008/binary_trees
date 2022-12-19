#include "binary_trees.h"

/**
 * print_tree_array - Prints tree nodes from array of tree nodes pointers
 * @array: The array of tree nodes pointers
 * @size: The size of the array
 */
void print_tree_array(binary_tree_t **array, size_t size)
{
	size_t i = 0;

	if (!array)
	{
		printf("Empty array!\n");
		return;
	}
	for (; i < size ; i++)
	{
		printf("\t%lu: ", i);
		if (!(array[i]))
			printf("NULL\n");
		else
		{
			printf("value = %d | ", array[i]->n);
			if (array[i]->parent)
				printf("parent = %d at %p | ", array[i]->parent->n,
					(void *) array[i]->parent);
			else
				printf("parent is NULL | ");
			if (array[i]->left)
				printf("left = %d at %p | ", array[i]->left->n,
					(void *) array[i]->left);
			else
				printf("left is NULL | ");
			if (array[i]->right)
				printf("right = %d at %p\n", array[i]->right->n,
					(void *) array[i]->right);
			else
				printf("right is NULL\n");
		}
	}
}


/**
 * check_level_complete - Traverse a binary tree level and check if it
 *				causes the tree not to be complete
 * @level_nodes: Array of nodes in the level
 *
 * Return: Dynamically allocated array of the nodes in the next level
 */
binary_tree_t **check_level_complete(binary_tree_t **level_nodes)
{
	binary_tree_t **nodes_list, **itr;
	size_t len = 0, i = 0;
	int no_more = 0;

	if (!level_nodes)
		return (NULL);
	while (level_nodes[len])
		len++;
	nodes_list = malloc(sizeof(*nodes_list) * (len * 2 + 1));
	if (!nodes_list)
		return (NULL);

	for (itr = level_nodes ; *itr ; itr++)
	{
		if ((no_more && ((*itr)->left || (*itr)->right)) ||
			((*itr)->right && !(*itr)->left))
		{
			nodes_list[0] = nodes_list[i++] = NULL;
			break;
		}
		else if (!(*itr)->left)
			no_more = 1;
		else if (!(*itr)->right)
			nodes_list[i++] = (*itr)->left,
			no_more = 1;
		else
			nodes_list[i++] = (*itr)->left,
			nodes_list[i++] = (*itr)->right;
	}
	nodes_list[i] = NULL, free(level_nodes);

	for (itr = nodes_list ; *itr && no_more && i ; itr++)
		if ((*itr)->left || (*itr)->right)
			nodes_list[0] = NULL;

	if (!*nodes_list && i)
		free(nodes_list), nodes_list = NULL;
	else if (no_more)
		nodes_list[0] = NULL;
	return (nodes_list);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root of the tree
 *
 * Return: (1) if the tree is complete or (0) otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **nodes_list;

	if (!tree)
		return (0);

	nodes_list = malloc(sizeof(*nodes_list) * 2);
	if (!nodes_list)
		return (0);

	nodes_list[0] = (binary_tree_t *) (long int) tree;
	nodes_list[1] = NULL;

	while (*nodes_list)
	{
		nodes_list = check_level_complete(nodes_list);
		if (!nodes_list)
			return (0);
	}

	free(nodes_list);
	return (1);
}

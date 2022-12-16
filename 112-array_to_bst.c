#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array
 * @array: The array
 * @size: The size of the array
 *
 * Return: The root node of the binary search tree on success
 *	or (NULL) otherwise
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i = 0;

	for (; i < size ; i++)
		bst_insert(&root, array[i]);

	return (root);
}

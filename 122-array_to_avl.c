#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: The array
 * @size: The size of the array
 *
 * Return: The root node of the AVL tree on success or (NULL) otherwise
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i = 0;

	for (; i < size ; i++)
		avl_insert(&root, array[i]);

	return (root);
}

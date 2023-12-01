#include "binary_trees.h"

/**
 * array_to_heap - Builds a max heap tree from an array
 * @array: The array
 * @size: The size of the array
 *
 * Return: The root node of the max heap tree on success or (NULL) otherwise
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i = 0;

	for (; i < size ; i++)
		heap_insert(&root, array[i]);

	return (root);
}

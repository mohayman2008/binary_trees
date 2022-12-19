#include "binary_trees.h"

size_t tree_size1(const binary_tree_t *tree);

/**
 * heap_to_sorted_array - Converts a max Heap tree to a sorted array
 * @heap: Pointer to the head of the max heap
 * @size: Pointer to integer to store the size of the returned array
 *
 * Return: The sorted array of integers or (NULL) on failure
 *		or in case heap or size equals NULL
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i;

	if (!heap || !size)
		return (NULL);

	*size = tree_size1(heap);

	array = malloc(sizeof(*array) * (*size));
	if (!array)
		return (NULL);

	for (i = 0 ; i < *size ; i++)
		array[i] = heap_extract(&heap);
	return (array);
}

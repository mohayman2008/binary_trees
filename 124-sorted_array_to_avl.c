#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: The sorted array
 * @size: The size of the array
 *
 * Return: The root node of the AVL tree on success or (NULL) otherwise
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t mid;

	if (!array || !size)
		return (NULL);

	mid = (size - 1) / 2;

	tree = binary_tree_node(NULL, array[mid]);
	if (!tree)
		return (NULL);

	tree->left = sorted_array_to_avl(array, mid);
	if (tree->left)
		tree->left->parent = tree;

	tree->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);
	if (tree->right)
		tree->right->parent = tree;

	return (tree);
}

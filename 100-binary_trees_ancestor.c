#include "binary_trees.h"

/**
 * binary_tree_ancestor - Finds the lowest common ancestor of two nodes
 *			in a binary tree
 * @first: Pointer to the first binary tree node
 * @second: Pointer to the second binary tree node
 *
 * Return: The lowest common ancestor node if found or (NULL) otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	binary_tree_t *itr1, *itr2, *second_n;

	if (!first || !second)
		return (NULL);

	itr1 = (binary_tree_t *) ((long int) first);
	second_n = (binary_tree_t *) ((long int) second);

	while (itr1)
	{
		itr2 = second_n;
		while (itr2)
		{
			if (itr1 == itr2)
				return (itr1);

			itr2 = itr2->parent;
		}

		itr1 = itr1->parent;
	}

	return (NULL);
}

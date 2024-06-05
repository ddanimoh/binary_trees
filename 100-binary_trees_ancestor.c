#include "binary_trees.h"
/**
 * binary_trees_ancestor - Finds lowest common ancestor of two nodes
 * @first: The first node
 * @second: The second node
 *
 * Return: Common ancestor node, or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *a, *b;

	if (first == NULL || second == NULL)
		return (NULL);

	/* If one of the nodes is the root, then root is the LCA */
	if (first == second)
		return ((binary_tree_t *)first);

	/* Move up the tree until we find a common ancestor */
	a = first;
	b = second;

	while (a != b)
	{
		a = a->parent == NULL ? second : a->parent;
		b = b->parent == NULL ? first : b->parent;
	}
	return ((binary_tree_t *)a);
}

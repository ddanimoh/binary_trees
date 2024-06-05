#include "binary_trees.h"
/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Root node of the tree to measure
 *
 * Return: Balance factor of tree, or 0 if NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
/**
 * binary_tree_height - Measures the height of binary tree
 * @tree: Root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

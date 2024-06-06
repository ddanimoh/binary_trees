#ifndef BINARY_H
#define BINARY_H

#include "binary_trees.h"
/**
 * max - Returns D max of #2 ints
 * @a: first int
 * @b: second intr
 * Return: max of 2 int
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Measures height of a binary tree
 * @tree: root node of the tree to measure
 * Return: Height of the tree, or 0
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * rotate_left - a left-rotation on binary tree
 * @tree: root node of tree to rotate
 * Return: root node of the tree once rotated
 */
avl_t *rotate_left(avl_t *tree)
{
	avl_t *new_root = tree->right;

	tree->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tree;

	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}

/**
 * rotate_right - right-rotation on binary tree
 * @tree: root node of the tree to rotate
 *
 * Return: root node of the tree once rotated
 */
avl_t *rotate_right(avl_t *tree)
{
	avl_t *new_root = tree->left;

	tree->left = new_root->right;
	if (new_root->right)
		new_root->right->parent = tree;

	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
#endif

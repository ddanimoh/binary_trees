#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs right-rotation on binary tree
 * @tree: Root node of the tree to rotate
 * Return: point to new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (!tree || !tree->left)
		return (tree);

	new_root = tree->left;
	temp = new_root->right;

	new_root->right = tree;
	tree->left = temp;

	if (temp)
		temp->parent = tree;

	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}

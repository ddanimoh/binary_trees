#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on binary tree
 * @tree: root node of the tree to rotate
 * Return: Root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (!tree || !tree->right)
		return (tree);

	new_root = tree->right;
	temp = new_root->left;

	new_root->left = tree;
	tree->right = temp;

	if (temp)
		temp->parent = tree;

	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}

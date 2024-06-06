#include "binary_trees.h"
#include "binary.h"
/**
 * balance_factor - Calculates balance factor of node
 * @node: Pointer to the node
 * Return: Balance factor
 */
int balance_factor(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (height(node->left) - height(node->right));
}
/**
 * rebalance - Rebalances an AVL tree
 * @node: node to rebalance from
 *
 * Return: root node after rebalancing
 */
avl_t *rebalance(avl_t *node)
{
	int balance;

	balance = balance_factor(node);

	if (balance > 1)
	{
		if (balance_factor(node->left) < 0)
			node->left = rotate_left(node->left);
		return (rotate_right(node));
	}
	else if (balance < -1)
	{
		if (balance_factor(node->right) > 0)
			node->right = rotate_right(node->right);
		return (rotate_left(node));
	}
	return (node);
}

/**
 * bst_insert - Inserts value in BST
 * @tree: root node of the BST to insert the value
 * @value: Value to insert
 * Return: created node, or NUL
 */
avl_t *bst_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	node = *tree;
	if (value < node->n)
	{
		if (node->left == NULL)
		{
			node->left = binary_tree_node(node, value);
			return (node->left);
		}
		else
			return (bst_insert(&(node->left), value));
	}
	else if (value > node->n)
	{
		if (node->right == NULL)
		{
			node->right = binary_tree_node(node, value);
			return (node->right);
		}
		else
			return (bst_insert(&(node->right), value));
	}
	return (NULL);
}

/**
 * avl_insert - Inserts value in an AVL
 * @tree: root node of the AVL tree to insert value
 * @value: Value to insert
 * Return: created node, or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *root;

	if (tree == NULL)
		return (NULL);

	node = bst_insert(tree, value);
	if (node == NULL)
		return (NULL);

	root = node;
	while (root->parent != NULL)
	{
		root = root->parent;
		root = rebalance(root);
	}
	*tree = root;
	return (node);
}

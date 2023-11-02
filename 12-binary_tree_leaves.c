#include "binary_trees.h"

/**
 * tree_is_leaf - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 * Return: The height of the tree, or 0 if the tree is NULL
 */
size_t tree_is_leaf(const binary_tree_t *node)
{
	int leaf = 0;

	if (node && !(node->left) && !(node->right))
		leaf = 1;

	return (leaf);
}

/**
 * binary_tree_leaves - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 * Return: The height of the tree below the root, or 0 if the tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree_is_leaf(tree))
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

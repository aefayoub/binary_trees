#include "binary_trees.h"

/**
 * tree_is_leaf - checks if a node is a leaf
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int tree_is_leaf(const binary_tree_t *node)
{
	int leaf = 0;

	if (node && !(node->left) && !(node->right))
		leaf = 1;

	return (leaf);
}
/**
 * tree_is_parent - Measure the height of a binary tree
 * @node: A pointer to the root node of the tree to measure
 * Return: The height of the tree, or 0 if the tree is NULL
 */
int tree_is_parent(const binary_tree_t *node)
{
	int parent = 0;

	if (node && (node->left && node->right))
		parent = 1;

	return (parent);
}

/**
 * binary_tree_is_full - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 * Return: The height of the tree below the root, or 0 if the tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree_is_leaf(tree))
		return (1);

	if (tree_is_parent(tree))
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}

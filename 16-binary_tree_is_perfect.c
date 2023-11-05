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
 * count_height - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 * Return: The height of the tree, or 0 if the tree is NULL
 */
int count_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
	{
		return (0);
	}

	right_h = count_height(tree->right);
	left_h = count_height(tree->left);

	if (left_h > right_h)
		return (left_h + 1);

	return (right_h + 1);

}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: tree root
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && count_height(tree->left) == count_height(tree->right))
	{
		if (count_height(tree->left) == -1)
			return (1);

		if (tree_is_parent(tree))
			return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));

		if (tree_is_leaf(tree->left) && tree_is_leaf(tree->right))
			return (1);
	}

	return (0);
}

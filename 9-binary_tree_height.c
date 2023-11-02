#include "binary_trees.h"

/**
 * count_height - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 * Return: The height of the tree, or 0 if the tree is NULL
 */
size_t count_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
	{
		return 0;
	}

	right_h = count_height(tree->right);
	left_h = count_height(tree->left);

	if (left_h > right_h)
		return left_h + 1;

	return (right_h + 1);

}

/**
 * binary_tree_height - Measure the height of a binary tree ignoring the root level
 * @tree: A pointer to the root node of the tree to measure
 * Return: The height of the tree below the root, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (count_height(tree) - 1);
}

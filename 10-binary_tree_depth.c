#include "binary_trees.h"

/**
 * count_depth - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 * Return: The height of the tree, or 0 if the tree is NULL
 */
size_t count_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (-1);
	}

	return (count_depth(tree->parent) + 1);

}

/**
 * binary_tree_depth - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 * Return: The height of the tree below the root, or 0 if the tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (count_depth(tree));
}

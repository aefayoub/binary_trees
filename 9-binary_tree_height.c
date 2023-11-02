#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 * Return: The height of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
	{
		return 0;
	}

	right_h = binary_tree_height(tree->right);
	left_h = binary_tree_height(tree->left);

	if (left_h > right_h)
		return left_h + 1;
	else
		return right_h + 1;

}

#include "binary_trees.h"

/**
 * count_height - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 * Return: The height of the tree, or 0 if the tree is NULL
 */
size_t count_height(const binary_tree_t *tree)
{
	size_t left_h = 0;
	size_t	right_h = 0;

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
 * binary_tree_level - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 * @level: level int
 * @func: pointer to a function
 * Return: The height of the tree below the root, or 0 if the tree is NULL
 */
void binary_tree_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_level(tree->left, level - 1, func);
		binary_tree_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - prints data in level-order traversal
 *
 * @tree: tree root
 * @func: pointer to a function
 * Return: no return
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height;
	size_t i;

	if (tree == NULL || func == NULL)
		return;

	height = count_height(tree);

	for (i = 1; i <= height; i++)
		binary_tree_level(tree, i, func);
}

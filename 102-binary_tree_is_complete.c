#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: tree root
 * Return: size of the tree or 0 if tree is NULL;
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

int is_complete(const binary_tree_t *tree, int i, int nodes)
{
	if (tree == NULL)
		return (1);

	if (i >= nodes)
		return (0);

	return (is_complete(tree->left, (2 * i) + 1, nodes) && is_complete(tree->right, (2 * i) + 2, nodes));
}

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes;

	if (tree == NULL)
		return (0);

	nodes = binary_tree_size(tree);

	return (is_complete(tree, 0, nodes));
}

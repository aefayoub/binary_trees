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

/**
 * binary_tree_uncle - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if ( first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (binary_tree_depth(first) < binary_tree_depth(second))
		return (binary_trees_ancestor(first, second->parent));

	if (binary_tree_depth(first) > binary_tree_depth(second))
		return (binary_trees_ancestor(first->parent, second));

	return (binary_trees_ancestor(first->parent, second->parent));
}

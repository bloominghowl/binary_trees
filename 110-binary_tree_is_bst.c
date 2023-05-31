#include "binary_trees.h"
#include <stdbool.h>

/**
 * greater_than - checks if all values in the binary tree are greater than a given value
 * @tree: pointer to the root node of the binary tree
 * @val: value to compare against
 *
 * Return: true if all values in the binary tree are greater than val, false otherwise
 */
int greater_than(const binary_tree_t *tree, int val)
{
	if (tree == NULL)
		return true;

	if (tree->n <= val)
		return false;

	return greater_than(tree->left, val) && greater_than(tree->right, val);
}

/**
 * less_than - checks if all values in the binary tree are less than a given value
 * @tree: pointer to the root node of the binary tree
 * @val: value to compare against
 *
 * Return: true if all values in the binary tree are less than val, false otherwise
 */
int less_than(const binary_tree_t *tree, int val)
{
	if (tree == NULL)
		return true;

	if (tree->n >= val)
		return false;

	return less_than(tree->left, val) && less_than(tree->right, val);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree (BST)
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	if (greater_than(tree->left, tree->n) && less_than(tree->right, tree->n))
	{
		if (tree->left != NULL && !binary_tree_is_bst(tree->left))
			return 0;

		if (tree->right != NULL && !binary_tree_is_bst(tree->right))
			return 0;

		return 1;
	}

	return 0;
}

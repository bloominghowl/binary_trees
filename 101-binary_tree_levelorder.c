#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - performs level-order traversal of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Description: The value in each node is passed as a parameter to the function.
 * If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	queue_t *queue = queue_create();
	if (queue == NULL)
		return;

	queue_push(queue, (void *)tree);

	while (!queue_is_empty(queue))
	{
		const binary_tree_t *current = (const binary_tree_t *)queue_pop(queue);
		func(current->n);

		if (current->left != NULL)
			queue_push(queue, (void *)current->left);

		if (current->right != NULL)
			queue_push(queue, (void *)current->right);
	}

	queue_delete(queue);
}

#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
        return NULL;

    const binary_tree_t *node1 = first;
    const binary_tree_t *node2 = second;

    while (node1 != node2) {
        node1 = node1->parent;
        node2 = node2->parent;

        if (node1 == NULL || node2 == NULL)
            return NULL;
    }

    return (binary_tree_t *)node1;
}

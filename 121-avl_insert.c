#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to be inserted
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    return avl_in(tree, value);
}

/**
 * check_balance - Checks and adjusts the balance of a node in an AVL tree
 * @node: Double pointer to the node to check
 * @value: Value to be inserted
 */
void check_balance(avl_t **node, int value)
{
    int balance;

    balance = binary_tree_balance(*node);

    if (balance > 1 && value < (*node)->left->n)
    {
        *node = binary_tree_rotate_right(*node);
        return;
    }

    if (balance < -1 && value > (*node)->right->n)
    {
        *node = binary_tree_rotate_left(*node);
        return;
    }

    if (balance > 1 && value > (*node)->left->n)
    {
        (*node)->left = binary_tree_rotate_left((*node)->left);
        *node = binary_tree_rotate_right(*node);
        return;
    }

    if (balance < -1 && value < (*node)->right->n)
    {
        (*node)->right = binary_tree_rotate_right((*node)->right);
        *node = binary_tree_rotate_left(*node);
        return;
    }
}

/**
 * avl_in - Recursive function to insert a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to be inserted
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
avl_t *avl_in(avl_t **tree, int value)
{
    avl_t *new_node = NULL;

    if (*tree == NULL)
    {
        new_node = binary_tree_node(NULL, value);
        if (new_node == NULL)
            return NULL;

        *tree = new_node;
        return new_node;
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_in(&(*tree)->left, value);
        if ((*tree)->left == NULL)
            return NULL;
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_in(&(*tree)->right, value);
        if ((*tree)->right == NULL)
            return NULL;
    }
    else
        return NULL;

    check_balance(tree, value);

    return *tree;
}

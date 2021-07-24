#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks is tree is AVL
 * @tree: pointer to root node
 * Return: 1 if AVL else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int height;

    if (!tree)
        return (0);
    return (check_if_is_avl(tree, INT_MIN, INT_MAX, &height));
}

/**
 * check_if_is_avl - recursively checks if tree is AVL
 * @tree: pointer to current root
 * @min: current min val
 * @max: current max val
 * @height: height of this tree by address
 * Return: true if is AVL else 0
 */
int check_if_is_avl(const binary_tree_t *tree, int min, int max, int *height)
{
    int tpm_1 = 0, tmp_2 = 0;

    if (!tree)
        return (1);
    if (tree->n <= min || tree->n >= max)
        return (0);
    if (!check_if_is_avl(tree->left, min, tree->n, &tpm_1) ||
        !check_if_is_avl(tree->right, tree->n, max, &tmp_2))
        return (0);
    *height = MAX(tpm_1, tmp_2) + 1;
    return (ABS(tpm_1 - tmp_2) <= 1);
}

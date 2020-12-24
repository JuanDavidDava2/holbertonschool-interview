#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent: is a pointer to the parent node of the node to create
 * @value: is the value to put in the node node
 * Return: pointer to the node node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
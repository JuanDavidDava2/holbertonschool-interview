#include "binary_trees.h"
/**
 * leftFuntion - check the left node
 * @node: is the cur node
 * Return: a node that contains one child
 */
heap_t *leftFuntion(heap_t *node)
{
  heap_t *l = NULL, *r = NULL, *cur = node;

  if (!cur)
    return (NULL);

  while (cur)
  {
    l = cur->left, r = cur->right;
    if (l && r)
    {
      if (!l->left || !l->right)
        return (l);
      else if (!r->left || !r->right)
        return (r);

      cur = l;
      continue;
    }
    else if (!l || !r)
      return (cur);
  }
  return (NULL);
}
/**
 * checkPropierty - check the propierty
 * @node: node to be evaluated
 */
void checkPropierty(heap_t *node)
{
  heap_t *parent, *i, *j;

  if (!node || !node->parent)
    return;
  parent = node->parent, j = parent->parent;
  i = (parent->right == node) ? parent->left : NULL;
  if (node->n > parent->n)
  {
    if (j)
    {
      if (parent == j->left)
        j->left = node;
      else
        j->right = node;
    }
    node->parent = j;
    parent->parent = node;
    parent->right = node->right;
    parent->left = node->left;
    if (node->left)
      node->left->parent = parent;
    if (node->right)
      node->right->parent = parent;
    if (i)
    {
      node->left = i;
      i->parent = node;
      node->right = parent;
    }
    else
      node->left = parent;
    checkPropierty(node);
  }
}
/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
  heap_t *node = NULL, *sheet = NULL;

  node = (heap_t *)binary_tree_node(NULL, value);
  if (!root || !node)
    return (NULL);
  if (!*root)
  {
    *root = node;
    return (node);
  }
  sheet = leftFuntion(*root);

  if (!sheet->left)
    sheet->left = node;
  else
    sheet->right = node;
  node->parent = sheet;
  checkPropierty(node);
  if (!node->parent)
    *root = node;
  return (node);
}
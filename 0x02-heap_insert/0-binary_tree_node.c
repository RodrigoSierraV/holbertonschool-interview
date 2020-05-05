#include "binary_trees.h"


/**
 * binary_tree_node - adds a new node to a binary tree
 *
 * @parent: Pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node or null
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	return (new);
}

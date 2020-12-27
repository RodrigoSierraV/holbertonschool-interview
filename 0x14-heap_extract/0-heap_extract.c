#include "binary_trees.h"

void last_node(heap_t *tree, heap_t **node, size_t h, size_t level);
size_t heap_height(const heap_t *tree);

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int extract, aux_n;
	heap_t *aux = *root, *node = NULL;

	if (!root || !*root)
		return (0);
	extract = aux->n;
	if (!aux->left && !aux->right)
	{
		*root = NULL;
		free(aux);
		return (extract);
	}
	last_node(aux, &node, heap_height(aux), 0);
	while (aux->left || aux->right)
	{
		aux_n = aux->n;
		if (!aux->right || aux->left->n > aux->right->n)
		{
			aux->n = aux->left->n;
			aux->left->n = aux_n;
			aux = aux->left;
		}
		else if (!aux->left || aux->left->n < aux->right->n)
		{
			aux->n = aux->right->n;
			aux->right->n = aux_n;
			aux = aux->right;
		}
	}
	aux->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (extract);
}

/**
 * last_node - finds the last node of the tree
 * @tree: pointer to root
 * @node: pointer
 * @h: height of the tree
 * @level: level in the tree
 * Return: no return
 **/
void last_node(heap_t *tree, heap_t **node, size_t h, size_t level)
{
	if (!tree)
		return;
	if (h == level)
	{
		*node = tree;
		return;
	}
	if (tree->left)
		last_node(tree->left, node, h, level + 1);
	if (tree->right)
		last_node(tree->right, node, h, level + 1);
}

/**
 * heap_height - height of a binary tree
 * @tree: pointer to the root
 * Return: height of the tree
 **/
size_t heap_height(const heap_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	right = heap_height(tree->right) + 1;
	left = heap_height(tree->left) + 1;
	if (left > right)
		return (left);
	else
		return (right);
}

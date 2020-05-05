#include "binary_trees.h"

/**
 * heap_h - measures the height of a node in a binary tree
 * @heap: pointer to the node to measure the height
 * Return: tree is NULL, return 0
 */

int heap_h(heap_t *heap)
{
	int left_hight = 0;
	int right_hight = 0;

	if (!heap)
		return (0);

	if (heap->left)
		left_hight = 1 + heap_h(heap->left);

	if (heap->right)
		right_hight = 1 + heap_h(heap->right);

	return ((left_hight > right_hight) ? left_hight : right_hight);
}

/**
 * heap_is_full - function that checks if a binary tree is full
 * @heap: pointer to the node to count the number of nodes
 * Return: 0 or 1 if tree is full
 */
int heap_is_full(const heap_t *heap)
{
	if (!heap)
		return (0);

	if (!heap->left && !heap->right)
		return (1);

	if (heap->left && heap->right)
	{
		if (heap_is_full(heap->left)
				&& heap_is_full(heap->right))
		return (1);
	}
	return (0);
}

/**
 * heap_find_node - function that checks if a binary tree is full
 * @heap: pointer to the node to count the number of nodes
 * Return: 0 or 1 if tree is full
 */
heap_t *heap_find_node(heap_t *heap)
{
	if (heap->left && !heap->right)
		return (heap);
	if (!heap->left && heap->right)
		return (heap);
	if (heap_is_full(heap->left) &&
		heap_is_full(heap->right))
	return (heap);
	return (heap);
}

/**
 * heap_insert - adds a new node to a max heap
 *
 * @root: Pointer to the root of the heap
 * @value: value to put in the new node
 *
 * Return: pointer to the new node or null
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *current, *insert;
	int complete, size;

	new = malloc(sizeof(heap_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;
	if (!*root)
	{
		*root = new;
		return (new);
	}
	complete = heap_is_full(*root);
	size = heap_h(*root);
	current = *root;
	if (complete == 1)
	{
		while (current->left)
		{
			current = current->left;
		}
		new->parent = current;
		current->left = new;
	}
	else
	{

		insert = heap_find_node(current);
		printf("%d AAAAAAAAAAAAQQQUIIIIIIIIII %d\n", size, insert->n);
		new->parent = insert;
		if (insert->left)
			insert->right = new;
		else
			insert->left = new;
	}
	return (new);
}

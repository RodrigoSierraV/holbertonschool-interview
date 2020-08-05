#include "binary_trees.h"


/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avl_tree = NULL;

	if (!array || size < 1)
		return (NULL);
	avl_tree = new_node();
	avl_tree = array_to_avl(0, size - 1, array, avl_tree);

	return (avl_tree);
}

/**
 * array_to_avl - builds an AVL tree from an array
 * @left: index of the left node
 * @right: index of the right node
 * @array: pointer to the first element of the array to be converted
 * @avl_tree: root of the avl_tree
 * Return: pointer to the root node of the tree
 */
avl_t *array_to_avl(size_t left, size_t right, int *array, avl_t *avl_tree)
{
	avl_t *right_node, *left_node;
	size_t mid;

	if (!avl_tree)
		return (NULL);
    mid = (left + right) / 2;
	avl_tree->n = array[mid];
    right_node = new_node();
    right_node->parent = avl_tree;
	if (mid > left && mid < right)
	{
		left_node = new_node();
		left_node->parent = avl_tree;
		avl_tree->left = array_to_avl(left, mid - 1, array, left_node);
		avl_tree->right = array_to_avl(mid + 1, right, array, right_node);
	}
	else if (mid + 1 == right)
	{
		avl_tree->right = right_node;
		right_node->n = array[right];
	}
	return (avl_tree);
}

/**
 * new_node - creates a new node
 * Return: pointer to the new node
 */
avl_t *new_node()
{
	avl_t *node;
    
    node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->left = NULL;
    node->parent = NULL;
    node->right = NULL;
	return (node);
}

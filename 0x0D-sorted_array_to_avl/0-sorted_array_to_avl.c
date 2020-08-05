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
	size_t mid;
	avl_t *root;

	if (left > right)
		return (NULL);

	mid = (left + right) / 2;
	root = new_node();
	root->parent = avl_tree;
	root->n = array[mid];
	if (!root)
		return (NULL);

	if (mid != left)
		root->left = array_to_avl(left, mid - 1, array, root);

	if (mid != right)
		root->right = array_to_avl(mid + 1, right, array, root);

	return (root);
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

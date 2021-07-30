#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * tree_node - create binary tree
 * @array: The array to convert
 * @start: initial index in array
 * @end: final index in array
 * @root: node to be created
 * Return: header
 */
avl_t *tree_node(int *array, int start, int end, avl_t **root)
{
	int middle;
	avl_t *new_node = NULL, *right = NULL, *left = NULL;

	if (start > end)
		return (NULL);
	middle = (start + end) / 2;

	tree_node(array, start, middle - 1, &left);
	tree_node(array, middle + 1, end, &right);

	new_node = malloc(sizeof(avl_t));
	new_node->n = array[middle];
	new_node->left = left;
	new_node->right = right;
	new_node->parent = NULL;

	if (left != NULL)
		left->parent = new_node;

	if (right != NULL)
		right->parent = new_node;

	*root = new_node;
	return (new_node);



}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: pointer to first element of array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL)
		return (NULL);

	if (tree_node(array, 0, (int)size - 1, &root) == NULL)
		return (NULL);

	return (root);
}

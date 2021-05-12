#include "binary_trees.h"

/**
 * binary_tree_height - size the height if a binary tree
 * @tree: binary tree
 * Return: height from the binary tree or 0 if tree is NULL
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int h_left, h_right;

	if (!tree)
		return (0);
	h_left = 0, h_right = 0;
	if (tree->left)
		h_left = 1 + binary_tree_height(tree->left)
	if (tree->right)
		h_right = 1 + binary_tree_height(tree->right)
	if (h_left > h_right)
		return (h_left)
	else
			return (h_right)

}

/**
 * binary_tree_is_perfect - Entry point
 * @tree: binary tree
 * Return: 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (!tree)
		return (0);
	l = tree->left;
	r = tree->right;
	if (!tree->left && !tree->right)
		return (1);
	if (!l || !r)
		return (0);

	if (binary_tree_height(l) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}

/**
 * heap_insert function that inserts a value into a Max Binary Heap
 * @root: root node of the heap
 * @value: integer to store in node
 * Return: pointer to inserted node or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent;
	heap_t *tmp;

	tmp_left = malloc(sizeof(heap_t));
	if (!new_node)
		return (NULL);

	if (*root == NULL)
	{
		*root = (binary_tree_node(*root, value));
		return *root;
	}
	if (*root->n < value)
	{
		tmp = *root;
		*root = (binary_tree_node(NULL, value);
		if (tmp->n 


	return new_node;
}

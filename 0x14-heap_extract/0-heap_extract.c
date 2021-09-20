#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - measures recursively the height of a binary tree
 * @tree: pointer to root node of tree to be measured the height
 *
 * Return: tree´s height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_h = 1 + tree_height(tree->left);

	if (tree->right)
		right_h = 1 + tree_height(tree->right);

	if (left_h > right_h)
		return (left_h);
	return (right_h);
}
/**
 * post_order - goes through a binary tree using post-order traversal
 * @tree: pointer to root node of tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 *
 * Return: No Return
 */
void post_order(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	post_order(tree->left, node, height);
	post_order(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *root_node, *node;

	if (!root || !*root)
		return (0);
	root_node = *root;
	value = root_node->n;
	if (!root_node->left && !root_node->right)
	{
		*root = NULL;
		free(root_node);
		return (value);
	}

	post_order(root_node, &node, tree_height(root_node));

	root_node->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(root_node);
	*root = root_node;
	return (value);
}

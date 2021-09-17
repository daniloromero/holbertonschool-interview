#include "binary_trees.h"


/*
 * heap_extract - extracts the root node of a Max Binay Heap
 * root: is a double pointer to the root node of the heap
 * Return: the value stored at the root node
 */

int heap_extract(heap_t **root)
{
     if (*root == NULL || root == NULL)
        return (0);
     return ((*root)->n);
}
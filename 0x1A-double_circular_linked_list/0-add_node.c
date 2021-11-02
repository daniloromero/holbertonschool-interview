#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - add node at end of double linked list
 * @list: double pointer to linked list
 * @str: string to copy into he new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node;


	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	if (!*list)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}
	new_node->next = *list;
	new_node->prev = (*list)->prev;
	(*list)->prev = new_node;
	new_node->prev->next = new_node;
	return (new_node);
}

/**
 * add_node_begin- add node at beginning of double linked list
 * @list: double pointer to linked list
 * @str: string to copy into he new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	if (!*list)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}
	new_node->next = *list;
	new_node->prev = (*list)->prev;
	(*list)->prev = new_node;
	if (new_node->prev)
		new_node->prev->next = new_node;
	*list = new_node;
	return (new_node);
}

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * recursion_palind- recursive call for singly linked list
 * @left: pointer to head of list
 * @right: pointer to tail of list
 * Return: number of nodes
 */

int recursion_palind(listint_t **left, listint_t *right)
{
	int is_palind;

	if (right == NULL)
		return (1);
	is_palind = recursion_palind(left, right->next);
	if (is_palind == 0)
		return (0);

	if ((*left)->n == right->n)
		is_palind = 1;
	*left = (*left)->next;
	return (is_palind);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: number of nodes
 */

int is_palindrome(listint_t **head)
{

	if (*head == NULL)
		return (1);
	return (recursion_palind(head, *head));
}

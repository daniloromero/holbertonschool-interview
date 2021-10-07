#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop -  finds the loop in a linked list.
 * @head: pointer to head of linked list
 * Return: address of node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (!head)
		return (NULL);
	slow = head;
	fast = head;
	while (fast != NULL && slow != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}
	return (NULL);
}

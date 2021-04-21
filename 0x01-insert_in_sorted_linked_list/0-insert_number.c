#include <stdlib.h>
#include "lists.h"

/**
 *  *insert_node - inserts a node into a listint_t list
 * @head: pointer to list
 * Return: new list with new node or NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
listint_t *new;
listint_t *current;
listint_t *prev;

current = *head;

new = malloc(sizeof(listint_t));
if (new == NULL)
    return (NULL);

new->n = number;
new->next = NULL;

if (current == NULL)
    current = new;
else
{
    while (current && current->n < new->n)
    {
        if (current->next == NULL)
            current->next = new;
        prev= current;
        current = current->next;
    }
    prev->next =new;
    new->next = current;
}
return (new);
}

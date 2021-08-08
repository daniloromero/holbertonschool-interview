#include "search.h"


/**
 * check_next_list -  searches for a value
 *
 * @check: is a pointer to the next list to search in
 * @value: is the value to search for
 *
 * Return: pointer first node where value is located or NULL
 */
skiplist_t *check_next_list(skiplist_t *check, int value)
{
	for (; check; check = check->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				check->index, check->n);
		if (check->n == value)
			return (check);
	}
	return (NULL);
}


/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list: pointer to the head of the skip list to search in
 * @value: tha value to search for
 * Return: pointer on the first node where the value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *check, *last, *tail;

	if (list == NULL)
		return (NULL);

	check = list;
	while (check)
	{
		if (check->express == NULL)
		{
			last = check->express;
			for (tail = list; tail; tail = tail->next)
				if (tail->next == NULL)
				{
					printf("Value found between indexes [%lu] and [%lu]\n",
							check->index, tail->index);
					break;
				}
			break;
		}
		if (check->express->n >= value)
		{
			last = check->express;
			printf("Value checked at index [%lu] = [%d]\n", last->index, last->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
					check->index, last->index);
			break;
		}
		check = check->express;
		printf("Value checked at index [%lu] = [%d]\n", check->index, check->n);
	}
	return (check_next_list(check, value));
}

#include "search_algos.h"


/**
 * recursive_binary - search for value in subarray
 * @array: pointer to array of integers
 * @init: start index of  subarray
 * @end: end index of subarray
 * @value: number given to be searched in array
 * Return: index of value otherwise -1
 */

int recursive_binary(int *array, size_t init, size_t end, int value)
{
	size_t i, L = init;
	size_t R = end;
	size_t m;


	if (init > end)
		return (-1);
	printf("Searching in array: ");
	if (end >= init)
	{
		m = L + (R - L) / 2;
		i = L;
		for (; i < R; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);
		if (array[m - 1] != value && array[m] == value)
			return (m);
		if (array[m] >= value)
			return (recursive_binary(array, L, m, value));
		return (recursive_binary(array, m + 1, end, value));
	}
	return (-1);
}
/**
 * advanced_binary - search for value in array
 * @array: pointer to array of integers
 * @size: size of array
 * @value: number given to be searched in array
 * Return: index of value otherwise -1
 */

int advanced_binary(int *array, size_t size, int value)
{

	if (array == NULL || size < 1)
		return (-1);

	return (recursive_binary(array, 0, size - 1, value));
}

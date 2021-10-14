#include "sort.h"

/**
 * copy_array - make a copy of array
 * @array: list of integer to make copy of
 * @i_start: index of array to start making copy
 * @i_end: index of array to stop making copy
 * @copy: empty array to copy @array
 * Return: void,
 */
void copy_array(int *array, int i_start, int i_end, int *copy)
{
	int k;

	for (k = i_start; k < i_end; k++)
		copy[k] = array[k];
}

/**
 * topdown_merge -  merger and sort of each split of main array
 * @array: is the copied array
 * @i_start: index where the first split starts
 * @i_middle: index where the second split starts
 * @i_end: index where the array ends
 * @copy: is the original array where the mergesort is performed
 * Return: void, prints the split that is selected to merge
 */
void topdown_merge(int *array, int i_start, int i_middle, int i_end, int *copy)
{
	int k;
	int i = i_start, j = i_middle;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&array[i_start], i_middle - i_start);
	printf("[right]: ");
	print_array(&array[i_middle], i_end - i_middle);
	for (k = i_start; k < i_end; k++)
	{
		if (i < i_middle && (j >= i_end || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i = i + 1;
		} else
		{
		copy[k] = array[j];
		j = j + 1;
		}
	}
}

/**
 * topdown_splitmerge - creates splits of array and calls merge function
 * @copy: array where @array was copied
 * @i_start: index where array starts
 * @i_end: index where array ends
 * @array: main array to be sorted
 * Return: void, prints merged splits as one array
 */
void topdown_splitmerge(int *copy, int i_start, int i_end, int *array)
{
	int i_middle;

	if (i_end - i_start <= 1)
		return;
	i_middle = (i_end + i_start) / 2;
	topdown_splitmerge(array, i_start, i_middle, copy);
	topdown_splitmerge(array, i_middle, i_end, copy);
	topdown_merge(copy, i_start, i_middle, i_end, array);
	printf("[Done]: ");
	print_array(&array[i_start], i_end - i_start);
}

/**
 * merge_sort - Sorts array of integers in ascending order using mergesort
 * @array: array of integers o be sorted
 * @size: length of array
 * Return: void, prints sorting steps and finally sorted array in place
 */
void merge_sort(int *array, size_t size)
{
	int *copy;

	copy = malloc(size * sizeof(int));
	if (copy == NULL)
		return;
	copy_array(array, 0, (int)size, copy);
	topdown_splitmerge(copy, 0, (int)size, array);
	free(copy);
}

#include "sort.h"
#include <stdlib.h>

/**
 * sort_idx - sorts each lsd in place of array
 *
 * @array: array of data to be sorted
 * @buff: malloc buffer
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: No Return
 */
void sort_idx(int *array, int **buff, int size, int lsd)
{
	int i, j, csize = 10, num;
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int carr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		buff[num][carr[num]] = array[i];
		carr[num] += 1;
	}

	for (i = 0, j = 0; i < csize; i++)
	{
		while (carr[i] > 0)
		{
			array[j] = buff[i][carr2[i]];
			carr2[i] += 1, carr[i] -= 1;
			j++;
		}
	}

	print_array(array, size);
}
/**
 * index_lsd - sort lsd into sub arrays
 *
 * @array: array of data to be sorted
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: No Return
 */
void index_lsd(int *array, int size, int lsd)
{
	int idx_lsd[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, num, csize = 10, **buff;

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		idx_lsd[num] += 1;
	}

	if (idx_lsd[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (i = 0; i < csize; i++)
		if (idx_lsd[i] != 0)
			buff[i] = malloc(sizeof(int) * idx_lsd[i]);

	sort_idx(array, buff, size, lsd);

	index_lsd(array, size, lsd + 1);

	for (i = 0; i < csize; i++)
		if (idx_lsd[i] > 0)
			free(buff[i]);
	free(buff);
}
/**
 * radix_sort - sorts array of integers in ascending order using Radix Sort
 * @array: array of integers >= 0
 * @size: the size of the array
 * Return: void, prints array each time significant digit increases
 */
void radix_sort(int *array, size_t size)
{
	int radix = 1;

	if (!array || size < 2)
		return;

	index_lsd(array, size, radix);
}

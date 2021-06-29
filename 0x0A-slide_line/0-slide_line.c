#include "slide_line.h"

/**
 * merge_line - merges array of integers as 2048 game
 *
 * @line: Array of integers
 * @size: Numbe of elements in @line
 * Return: void
 */
void merge_line(int *line, size_t size)
{
	int a, b = 0;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		j = i + 1;
		if (line[i] == 0)
			continue;
		a = line[i], b = line[j];
		while (b == 0)
		{
			j++;
			b = line[j];
		}
		if (a == b)
		{
			line[i] += b;
			line[j] = 0;
			a = b = 0;
			i = i + 1;
		}
	}
}

/**
 * reverse_line - reverses array of integers
 *
 * @line: Array of integers
 * @size: Numbe of elements in @line
 * Return: 1 upon success, or 0 upon failure
 */
void reverse_line(int *line, size_t size)
{
	size_t i, j;
	int swap;

	for (i = 0, j = size - 1; i < size / 2; i++, j--)
	{
		swap = line[i];
		line[i] = line[j];
		line[j] = swap;
	}
}


/**
 * slide - reverses array of integers
 *
 * @line: Array of integers
 * @size: Numbe of elements in @line
 * @direction: direction for the merge can be SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */
int slide(int *line, size_t size, int direction)
{
	size_t i, j;

	for (i = 0; i < size - 2; i++)
	{
		j = i;
		if (line[i] != 0)
			continue;
		if (line[i] == 0)
		{
			while (line[j] == 0 && j <= (size - 2))
				j++;

			line[i] = line[j];
			line[j] = 0;
		}
	}
	if (direction == 5)
		reverse_line(line, size);
	return (1);
}

/**
 * slide_line - slides and merges array of inteers as 2048 game
 *
 * @line: Array of integers
 * @size: Numbe of elements in @line
 * @direction: direction for the merge can be SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */


int slide_line(int *line, size_t size, int direction)
{

	if (direction == 4)
	{
		merge_line(line, size);
	}
	if (direction == 5)
	{
		reverse_line(line, size);
		merge_line(line, size);
	}
	slide(line, size, direction);

	return (1);
}

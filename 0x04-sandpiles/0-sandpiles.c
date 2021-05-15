#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple - topples sandpile until every position is less or equal to 3
 * @grid1: first sandpile
 * @grid2: second sandpiles
 * Return: toppled sandpile
 */
void topple(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	printf("=\n");
	print_grid(grid2);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid2[i][j] > 3)
			{
				if (i == 0)
					grid1[i + 1][j] += 1;
				if (i == 1)
				{
					grid1[i - 1][j] += 1;
					grid1[i + 1][j] += 1;
				}
				if (i == 2)
					grid1[i - 1][j] += 1;
				if (j == 0)
					grid1[i][j + 1] += 1;
				if (j == 1)
				{
					grid1[i][j - 1] += 1;
					grid1[i][j + 1] += 1;
				}
				if (j == 2)
					grid1[i][j - 1] += 1;
				grid1[i][j] -= 4;
			}
		}
	}
	stable_sandpile(grid1, grid2);
}


/**
 * stable_sandpile - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpiles
 * Return: Result of addition of two sandpiles
 */
int stable_sandpile(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int top = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = grid1[i][j];
			if (grid1[i][j] > 3)
				top = 1;
		}
	}
	if (top == 1)
	{
		topple(grid1, grid2);
		return (1);
	}
	else
		return (0);
}
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpiles
 * Return: Result of addition of two sandpiles
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	stable_sandpile(grid1, grid2);
}

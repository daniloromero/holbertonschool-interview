#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: void
 */

void menger(int level)
{
	int i, j, y, x, gap, height, width = 0;

	height = width = pow(3, level);
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			gap = 0;
			y = i;
			x = j;
			while (y > 0)
			{
				if (y % 3 == 1 && x % 3 == 1)
					gap = 1;
				y /= 3;
				x /= 3;
			}
			gap == 0 ? putchar('#') : putchar(' ');
		}
		printf("\n");
	}

}

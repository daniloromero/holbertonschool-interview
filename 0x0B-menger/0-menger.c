#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: void
 */

void menger(int level)
{
	int i, j, height, width = 0;

	height = width = pow(3, level);
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (j == width - 1)
			{
				printf("#\n");
				continue;
			}
			else
				putchar('#');
		}
	}

}

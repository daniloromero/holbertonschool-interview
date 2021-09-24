#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints file name followed by new line
 * @argc: counter of arguments
 * @argv:number to be multiplie
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int rslt;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	rslt = atoi(argv[1]) * atoi(argv[2]);
	printf("%d\n", rslt);
	return (0);
}

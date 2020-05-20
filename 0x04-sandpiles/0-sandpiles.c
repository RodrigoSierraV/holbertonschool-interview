#include "sandpiles.h"

/**
 * print_grid - print the sandpile
 *
 * @grid: sandpile
 *
 * Return: void
 **/
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
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
 * calculate - sandpile distribution
 *
 * @grid1: sandpile
 *
 **/
void calculate(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if (i - 1 >= 0)
					grid1[i - 1][j] = grid1[i - 1][j] + 1;
				if (i + 1 <= 2)
					grid1[i + 1][j] = grid1[i + 1][j] + 1;
				if (j - 1 >= 0)
					grid1[i][j - 1] = grid1[i][j - 1] + 1;
				if (j + 1 <= 2)
					grid1[i][j + 1] = grid1[i][j + 1] + 1;
			}
		}
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 *
 *@grid1: first sandpile
 *
 *@grid2: secondsandpile
 *
 **/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, not_stable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3)
				not_stable = 1;
		}
	}

	while (not_stable)
	{
		print_grid(grid1);
		calculate(grid1);
		not_stable = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
					not_stable = 1;
			}
		}
	}
}

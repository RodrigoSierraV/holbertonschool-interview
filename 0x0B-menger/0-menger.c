#include "menger.h"

/**
 * menger - Function menger
 *
 * @level: level of deep in Merge Sponge
 *
 * Return: None
 */
void menger(int level)
{
	int side = 1, i, j, x, y;

	if (level == 0)
		printf("#\n");
	else if (level < 0)
		return;

	for (i = 0; i < level; i++)
		side *= 3;
	for (i = 0; i < side && level > 0; i++)
	{
		for (j = 0; j < side; j++)
		{
			x = i;
			y = j;
			while (x > 0 && y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					printf(" ");
					break;
				}
				x /= 3;
				y /= 3;
			}
			if (x % 3 != 1 || y % 3 != 1)
				printf("#");
		}
		printf("\n");
	}
}

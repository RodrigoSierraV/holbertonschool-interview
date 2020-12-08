#include "search_algos.h"
#include <unistd.h>

/**
 * advanced_binary - searches for a value in a sorted array
 * of integers using the Binary search algorithm - always the first one
 * @array:  pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return:  index where value is located otherwise -1
 *
 **/
int advanced_binary(int *array, size_t size, int value)
{
	int max = size - 1, min = 0, guess = (max + min) / 2;
	size_t i = 1;

	if (array == NULL || size == 0)
		return (-1);
	printf("Searching in array: %d", array[0]);
	while (i < size)
		printf(", %d", array[i++]);
	printf("\n");
	while (min != max && min < max)
	{
		if (array[guess] == value)
		{
			if (array[guess - 1] == value)
				guess -= 1;
			else
				return (guess);
		}
		else if (array[guess] > value)
		{
			max = guess - 1;
			guess = (max + min) / 2;
		}
		else if (array[guess] < value)
		{
			min = guess + 1;
			guess = (max + min) / 2;
		}
		sleep(2);
	}
	return (-1);
}

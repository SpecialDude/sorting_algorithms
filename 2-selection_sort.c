#include "sort.h"

/**
 * selection_sort - Sort array using Selection Algorithm
 *
 * @array: Array to be sorted
 * @size: Number of elements in array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, small;
	int temp, min;

	for (i = 0; i < size; i++)
	{
		small = i;
		min = array[i];

		for (j = i + 1; j < size; j++)
			if (array[j] < array[small])
			{
				small = j;
			}

		if (min != array[small])
		{
			temp = array[i];
			array[i] = array[small];
			array[small] = temp;
			print_array(array, size);
		}
	}
}

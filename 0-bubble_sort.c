#include "sort.h"

/**
 * bubble_sort - Sorts array using Bubble sort Algorith
 *
 * @array: Array to be sorted
 * @size: Number of element to be sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int sorted, temp;

	if (array == NULL)
		return;

	j = 0;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		j++;

		for (i = 0; i < size - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				sorted = 0;
				print_array(array, size);
			}
		}
	}
}

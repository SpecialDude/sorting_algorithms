#include "sort.h"

/**
 * get_max_element - Returns the max element from array
 *
 * @array: Array of integers
 * @size: Number of elements in array
 *
 * Return: int (maximum element in array)
 */
int get_max_element(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * counting_sort - Sorts array using Counting Sorting Algorithm
 *
 * @array: Array of postive integers to be sorted
 * @size: Number of elements in array
 */
void counting_sort(int *array, size_t size)
{
	int *counts, *sorted_array;
	size_t c_size, i;

	if (!array)
		return;

	c_size = get_max_element(array, size) + 1;
	counts = malloc(sizeof(int) * c_size);
	if (!counts)
		return;

	for (i = 0; i < c_size; i++)
		counts[i] = 0;
	for (i = 0; i < size; i++)
		counts[array[i]] = counts[array[i]] + 1;
	for (i = 1; i < c_size; i++)
		counts[i] = counts[i] + counts[i - 1];

	print_array(counts, c_size);

	sorted_array = malloc(sizeof(*array) * size);
	if (!sorted_array)
	{
		free(counts);
		return;
	}
	i = size;
	while (1)
	{
		counts[array[i]] = counts[array[i]] - 1;
		sorted_array[counts[array[i]]] = array[i];
		if (i == 0)
			break;
		i--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(counts);
	free(sorted_array);
}

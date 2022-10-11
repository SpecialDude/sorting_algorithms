#include "sort.h"

/**
 * get_knuth_interval - Calculates the knuth interval
 *
 * @array_size: Size of array
 *
 * Return: size_t (Calculated interval)
 */
size_t get_knuth_interval(size_t array_size)
{
	size_t interval, limit;

	interval = 1;
	limit = array_size / 3;

	while (interval <= limit)
		interval = interval * 3 + 1;

	return (interval);
}

/**
 * shell_sort - Sort array using Shell Sort Algorithm
 *
 * @array: Array to sorted
 * @size: Number of elements in array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, index, interval;
	int key;

	interval = get_knuth_interval(size);

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			key = array[i];
			index = i;
			while ((index > interval - 1) && (array[index - interval] >= key))
			{
				array[index] = array[index - interval];
				index -= interval;
				print_array(array, size);
			}
			array[index] = key;
		}
		interval = (interval - 1) / 3;
	}
}

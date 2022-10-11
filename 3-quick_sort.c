#include "sort.h"

/**
 * lomuto_partition - Partition array, using Lomuto Partitioning
 *
 * @array: Array to be partitioned
 * @low: least index in array
 * @high: Heighest index in array
 * @size: Number of element in array
 *
 * Return: size_t (Partition index)
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i, pivot, temp;
	size_t j;

	pivot = array[high];

	i = low - 1;
	for (j = (size_t)low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			++i;

			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sorting - Quick Sorting main code
 *
 * @array: Array to be sorted
 * @low: Least Index
 * @high: Highest Index
 * @size: Number of elements in array
 */
void quick_sorting(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sorting(array, low, p - 1, size);
		quick_sorting(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts array with Quick Sort Algorithm
 *
 * @array: Array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	quick_sorting(array, 0, size - 1, size);
}

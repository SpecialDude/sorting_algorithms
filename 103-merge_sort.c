#include "sort.h"

/**
 * print_array2- Just another function to print array
 *
 * @array: Array to be printed
 * @start: Index to start printing from
 * @end: Index to stop printing
 */
void print_array2(int *array, size_t start, size_t end)
{
	size_t i;

	i = start;

	while (array && i < end)
	{
		if (i > start)
			printf(", ");

		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * top_down_merge - Merge Arrays
 *
 * @array: Array of integers
 * @start: Starting index
 * @mid: Middle index
 * @end: Ending index
 * @copy_array: Copy of array
 */
void top_down_merge(
	int *array, size_t start, size_t mid, size_t end, int *copy_array
)
{
	size_t i, j, k;

	i = start;
	j = mid;

	printf("Merging...\n");
	printf("[Left]: ");
	print_array2(array, start, mid);
	printf("[Right]: ");
	print_array2(array, mid, end);

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			copy_array[k] = array[i];
			i = i + 1;
		}
		else
		{
			copy_array[k] = array[j];
			j = j + 1;
		}
	}

	printf("[Done]: ");
	print_array2(copy_array, start, end);
}

/**
 * top_down_split_merge - Splits array and then merge
 *
 * @copy_array: Copy of array
 * @start: Starting index
 * @end: Ending index
 * @array: Array of integers
 */
void top_down_split_merge(
	int *copy_array, size_t start, size_t end, int *array
)
{
	size_t mid;

	if (end - start <= 1)
		return;

	mid = (end + start) / 2;

	top_down_split_merge(array, start, mid, copy_array);
	top_down_split_merge(array, mid, end, copy_array);

	top_down_merge(copy_array, start, mid, end, array);

}

/**
 * merge_sort - Sort array using Merge Sort Algorithm
 *
 * @array: Array of integers to be sorted
 * @size: Number of elements in array
 */
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i;

	if (!array)
		return;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	top_down_split_merge(copy, 0, size, array);

	free(copy);
}

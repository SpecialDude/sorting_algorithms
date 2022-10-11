#include "sort.h"

/**
 * shift_down - Shift down heap
 *
 * @array: Array of integers representing a heap DS
 * @start: Starting index
 * @end: Ending index
 * @size: Number of elements in array
 */
void shift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root, child, swap;
	int temp;

	root = start;

	while ((2 * root + 1) <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] <= array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * heapify - Converts an array of integers into a heap
 *
 * @array: Array to be converted
 * @size: Number of elements in array
 */
void heapify(int *array, size_t size)
{
	ssize_t start;

	start = ((size - 1) - 1) / 2;

	while (start >= 0)
	{
		shift_down(array, start, size - 1, size);

		--start;
	}
}

/**
 * heap_sort - Sort Array using Heap Sorting Algorithm
 *
 * @array: Array to be sorted
 * @size: Number of elements in array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (!array)
		return;

	heapify(array, size);
	end = size - 1;

	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;

		print_array(array, size);

		--end;
		shift_down(array, 0, end, size);
	}
}

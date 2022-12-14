#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int array2[] = {34, 100, 34, 76, -4, 89, 45, -10, 5, 650, 332, 90, -76, -5, 10, 8, 9, 14, 56};
	size_t n = sizeof(array) / sizeof(array[0]);
	size_t n2 = sizeof(array2) / sizeof(array2[0]);

	print_array(array, n);
	printf("\n");
	quick_sort(array, n);
	printf("\n");
	print_array(array, n);

	printf("<---------------------------------->\n");
	print_array(array2, n2);
	printf("\n");
	quick_sort(array2, n2);
	printf("\n");
	print_array(array2, n2);
	return (0);
}

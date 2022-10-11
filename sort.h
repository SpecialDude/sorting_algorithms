#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

typedef long ssize_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);

ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void quick_sorting(int *array, ssize_t low, ssize_t high, size_t size);
size_t get_knuth_interval(size_t array_size);
void swap_two_nodes(
	listint_t *left, listint_t *right,
	listint_t **head, listint_t **tail
);
int get_max_element(int *array, size_t size);
void print_array2(int *array, size_t start, size_t end);
void top_down_merge(
	int *array, size_t start, size_t mid, size_t end, int *copy_array
);
void top_down_split_merge(
	int *copy_array, size_t start, size_t end, int *array
);
void shift_down(int *array, size_t start, size_t end, size_t size);
void heapify(int *array, size_t size);
#endif

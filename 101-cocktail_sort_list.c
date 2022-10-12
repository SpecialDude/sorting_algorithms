#include "sort.h"

/**
 * swap_two_nodes - Swaps two nodes of a doubly linked list
 *
 * @left: Pointer to node on the left
 * @right: Pointer to node on the right
 * @head: Pointer to the head of the list (if available)
 * @tail: Pointer to the tail of the list (if available)
 */
void swap_two_nodes(
	listint_t *left, listint_t *right,
	listint_t **head, listint_t **tail
)
{
	left->next = right->next;
	right->prev = left->prev;

	left->prev = right;
	right->next = left;

	if (left->next)
		left->next->prev = left;
	else
		if (tail)
			(*tail) = left;
	if (right->prev)
		right->prev->next = right;
	else
		if (head)
			(*head) = right;
}

/**
 * cocktail_sort_list - Sort linked list using
 * Cocktail Sorting Algorithm
 *
 * @list: Doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *l_current, *l_next, *l_prev;
	int sorted;

	if (!list || !(*list))
		return;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		l_current = *list;
		while (l_current && l_current->next)
		{
			if (l_current->n > l_current->next->n)
			{
				l_next = l_current->next;
				swap_two_nodes(l_current, l_next, list, NULL);
				sorted = 0;
				print_list(*list);
			}
			else
				l_current = l_current->next;
		}

		if (sorted)
			break;

		while (l_current && l_current->prev)
		{
			if (l_current->n < l_current->prev->n)
			{
				l_prev = l_current->prev;
				swap_two_nodes(l_prev, l_current, list, NULL);
				sorted = 0;
				print_list(*list);
			}
			else
				l_current = l_current->prev;
		}
	}
}

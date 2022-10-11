#include "sort.h"

/**
 * insertion_sort_list - Sorts linked list by Insertion Algorithm
 *
 * @list: Linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *l_temp, *l_current, *l_prev;

	if (*list == NULL)
		return;

	l_temp = *list;

	while (l_temp)
	{
		l_current = l_temp;

		while (l_current && l_current->prev && l_current->n < l_current->prev->n)
		{
			l_prev = l_current->prev;

			l_prev->next = l_current->next;
			l_current->prev = l_prev->prev;

			if (l_prev->prev)
				l_prev->prev->next = l_current;
			else
				(*list) = l_current;

			if (l_current->next)
				l_current->next->prev = l_prev;

			l_current->next = l_prev;
			l_prev->prev = l_current;

			print_list(*list);
		}
		l_temp = l_temp->next;
	}
}

#include "sort.h"

/**
 * swap_nodes - function for swaping node
 * @h: ptr to head of db list
 * @n1: ptr to 1st nde
 * @n2: ptr to sec nde
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - function for sorting db list
 * @list: ptr to the head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itteerr, *insertt, *tmmpp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itteerr = (*list)->next; itteerr != NULL; itteerr = tmmpp)
	{
		tmmpp = itteerr->next;
		insertt = itteerr->prev;
		while (insertt != NULL && itteerr->n < insertt->n)
		{
			swap_nodes(list, &insertt, itteerr);
			print_list((const listint_t *)*list);
		}
	}
}

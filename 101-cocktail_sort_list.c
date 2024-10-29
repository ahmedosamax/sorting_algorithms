#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - for swaping node
 * @list: ptr to the head
 * @tail: ptr to the tail
 * @shaker: ptr to the current swaping
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmpp;
	else
		*list = tmpp;
	tmpp->prev = (*shaker)->prev;
	(*shaker)->next = tmpp->next;
	if (tmpp->next != NULL)
		tmpp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmpp;
	tmpp->next = *shaker;
	*shaker = tmpp;
}

/**
 * swap_node_behind - for swaping nodes
 * @list: ptr to head of list
 * @tail: ptr to tail of list
 * @shaker: ptr to current swaping
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmpp;
	else
		*tail = tmpp;
	tmpp->next = (*shaker)->next;
	(*shaker)->prev = tmpp->prev;
	if (tmpp->prev != NULL)
		tmpp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmpp;
	tmpp->prev = *shaker;
	*shaker = tmpp;
}

/**
 * cocktail_sort_list - sorting db list
 * @list: pointer to head list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *taill, *shakeer;
	bool s_n_str = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (taill = *list; taill->next != NULL;)
		taill = taill->next;

	while (s_n_str == false)
	{
		s_n_str = true;
		for (shakeer = *list; shakeer != taill; shakeer = shakeer->next)
		{
			if (shakeer->n > shakeer->next->n)
			{
				swap_node_ahead(list, &taill, &shakeer);
				print_list((const listint_t *)*list);
				s_n_str = false;
			}
		}
		for (shakeer = shakeer->prev; shakeer != *list;
				shakeer = shakeer->prev)
		{
			if (shakeer->n < shakeer->prev->n)
			{
				swap_node_behind(list, &taill, &shakeer);
				print_list((const listint_t *)*list);
				s_n_str = false;
			}
		}
	}
}

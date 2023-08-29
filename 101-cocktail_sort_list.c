#include "sort.h"

/**
 * swap_nodes - function swaps two nodes in a doubly linked list.
 * @list: a pointer to a pointer to the head of the linked list
 * @l: a pointer to the first node to be swapped,left item to swap.
 * @r: a pointer to the second node to be swapped,right item to swap.
 */
void swap_nodes(listint_t **list, listint_t *l, listint_t *r)
{
	listint_t *prev_l = NULL, *nxt_l = NULL, *prev_r = NULL, *nxt_r = NULL;

	if ((l == NULL) || (r == NULL) || (list == NULL) || (l == r))
		return;
	prev_l = l->prev, nxt_l = l->next, prev_r = r->prev, nxt_r = r->next;
	if (l->prev == r)
	{
		l->next = r, l->prev = prev_r, r->next = nxt_l, r->prev = l;
		if (prev_r != NULL)
			prev_r->next = l;
		if (nxt_l != NULL)
			nxt_l->prev = r;
	}
	else if (l->next == r)
	{
		l->next = nxt_r, l->prev = r, r->next = l, r->prev = prev_l;
		if (prev_l != NULL)
			prev_l->next = r;
		if (nxt_r != NULL)
			nxt_r->prev = l;
	}
	else
	{
		l->next = nxt_r, l->prev = prev_r, r->next = nxt_l, r->prev = prev_l;
		if (prev_l != NULL)
			prev_l->next = r;
		if (nxt_l != NULL)
			nxt_l->prev = r;
		if (prev_r != NULL)
			prev_r->next = l;
		if (nxt_r != NULL)
			nxt_r->prev = l;
	}
	if (l->prev == NULL)
		*list = l;
	if (r->prev == NULL)
		*list = r;
}

/**
 * get_tail - function retrieves the tail node of a doubly linked list.
 * @list: A pointer to a pointer to the head of the linked list.
 *
 * Return: Tail of the linked list, otherwise NULL.
 */
listint_t *get_tail(listint_t **list)
{
	listint_t *node = NULL;

	if (list != NULL)
	{
		node = *list;
		while ((node != NULL) && (node->next != NULL))
			node = node->next;
	}
	return (node);
}

/**
 * cocktail_sort_list - function sorts a doubly linked list
 * using the cocktail shaker sort algorithm.
 * @list: a pointer to pointer list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = FALSE;
	listint_t *node = NULL, *next = NULL, *tmp;

	if (list == NULL)
		return;
	do {
		node = *list;
		next = (node == NULL ? NULL : node->next);
		swapped = FALSE;
		while ((node != NULL) && (next != NULL))
		{
			tmp = next;
			if (node->n > next->n)
			{
				swap_nodes(list, node, next);
				swapped = TRUE;
				print_list(*list);
			}
			node = tmp, next = (node == NULL ? NULL : node->next);
		}
		if (!swapped)
			break;
		swapped = FALSE;
		next = get_tail(list);
		node = next == NULL ? NULL : next->prev;
		while ((node != NULL) && (next != NULL))
		{
			tmp = node;
			if (node->n > next->n)
			{
				swap_nodes(list, node, next);
				swapped = TRUE;
				print_list(*list);
			}
			next = tmp, node = next == NULL ? NULL : next->prev;
		}
	} while (swapped);
}

#include "sort.h"
/**
 * insertion_sort_list - sort a doubly linked list in ascending order
 * @list: double pointer to the head of the linked list
 * that is unSorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	/*checks if the list or next pointer of head node is NULL*/
	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;/* point to second node in the list*/
	while (node)
	{
		/*ensures there is a previous node, and to determine if the*/
		/*previous node's value is greater than the current node's value*/
		while ((node->prev) && (node->prev->n > node->n))
		{
			/*swaps current node with its prev node and returns new curr node*/
			node = swap_node(node, list);
			print_list(*list);/*display the current state of the list*/
		}
		node = node->next;/*node pointer is moved to next node in list*/
	}
}
/**
 *swap_node - function is used to swap two adjacent
 *nodes in a doubly linked list
 *@node: pointer to the current node to be swapped
 *@list: a pointer to a pointer to the head of the linked list
 *Return: return pointer of current node
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;/*connect prev node to next node of curr node*/
	if (current->next)/*there is a next node*/
		current->next->prev = back;/*to connect current node to previous node*/
	current->next = back;/*connect the current node to the node before back.*/
	current->prev = back->prev;
	back->prev = current;/* connect the previous node to the current node.*/
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}

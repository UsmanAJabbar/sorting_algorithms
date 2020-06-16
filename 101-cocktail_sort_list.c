#include "sort.h"

/**
 * cocktail_sort_list - sorts a linked list
 * with the cocktail sort algorithm
 * @list: address of the head to the linked
 * list
 * Return: Always Void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int check;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	check = verify(&(*list));	/* Check of the array is sorted before entering */

	while (check == 1)		/* Keep running until the verify func doesn't approve */
	{
		/* Forward Check */
		for (; temp->next; temp = temp->next)
			if (temp->n > temp->next->n)
			{
				*list = swap_list(&(*list), temp, temp->next);
				temp = temp->prev, print_list(*list);
			}

		check = verify(&(*list));	/* Check if the list has been sorted */

		/* Reverse Check */
		if (check == 1 && temp->prev)
			for (; temp->prev; temp = temp->prev)
				if (temp->n < temp->prev->n)
				{
					*list = swap_list(&(*list), temp, temp->prev);
					temp = temp->next, print_list(*list);
				}

		check = verify(&(*list));
	}
}

/**
 * swap_list - swaps two nodes
 * and if the swapped node happens to
 * become the head, updates the head
 * @head: address to the head of the
 * linked list.
 * @first: node1
 * @second: node2
 * Return: Address of the head to the
 * linked list.
 */
listint_t *swap_list(listint_t **head, listint_t *first, listint_t *second)
{
	listint_t *temp;

	if (first && second)
	{
		/* SWAPPING THE NEXTS */
		temp = first->next, first->next = second->next, second->next = temp;

		if (first->next)
			first->next->prev = first;
		if (second->next)
			second->next->prev = second;

		/* SWAPPING THE PREVS */
		temp = first->prev, first->prev = second->prev, second->prev = temp;

		if (first->prev)
			first->prev->next = first;
		if (second->prev)
			second->prev->next = second;

		/* Check if the head needs to be updated */
		if (!first->prev)
			*head = first;
		else if (!second->prev)
			*head = second;

		return (*head);
	}
	return (NULL);
}

/**
 * verify - verifies whether a
 * linked list is sorted or not
 * @list: linked list
 * Return: 0 if sorted | 1 if not
 */
int verify(listint_t **list)
{
	listint_t *temp = *list;

	if (temp && temp->next)
	{
		for (temp = *list; temp->next != NULL; temp = temp->next)
			if (temp->n > temp->next->n)
				return (1);	/* Failed - List isn't sorted */
		return (0);	/* Aye Aye Captain! All good */
	}
	else
		return (1); /* Failed because we don't have two nodes */
}

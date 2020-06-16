#include "sort.h"
#include <stdio.h>

void swap_node(listint_t **list, listint_t *node1, listint_t *node2);
/**
 * cocktail_sort_list - a function to sort a linked list with a back and
 * forth max - min algorithmic approach. Max values will be bubbled up
 * with their node swapping to the correct place in the list while min
 * values will be bubbled down to their place.
 * @list: a doubly linked list with integer values as node->n
 * Return: Always void, it's pointers!
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *mover, *bubble_up, *bubble_down;
	int start = 0, end = 0, moving = 0, sort = 1, min, max;

	if (list == NULL || (*list) == NULL)
		return;
	mover = *list;
	max = mover->n;
	while (mover->next != NULL)
	{
		if (max != mover->n || max > mover->n)
			sort = 0;
		mover = mover->next;
		end++;
	}
	if (sort == 1)
		return;
	mover = (*list);
	while (start < end)
	{
		max = mover->n;
		while (moving < end)
		{
			mover = mover->next;
			if (mover->n > max)
			{
				max = mover->n;
				bubble_up = mover;
			}
			else
			{
				swap_node(list, bubble_up, mover);
				mover = bubble_up;
				print_list(*list);
			}
			moving++;
		}
		end--;
		min = mover->n;
		while (moving > start)
		{
			mover = mover->prev;
			if (mover->n < min)
			{
				min = mover->n;
				bubble_down = mover;
			}
			else
			{
				swap_node(list, mover, bubble_down);
				print_list(*list);
				mover = bubble_down;
			}
			moving--;
		}
		start++;
	}
}

/**
 * swap_node - a fucntion to swap two nodes in a doubly linked list
 * @list: a doubly linked list
 * @node1: the first node
 * @node2: the second node to be swapped
 * Return: void, no return
 */

void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		(*list) = node2;
	node2->prev = node1->prev;
	node1->prev = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->next = node1;
}

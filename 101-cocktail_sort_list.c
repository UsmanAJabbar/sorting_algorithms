#include "sort.h"
#include <stdio.h>

void swap_node(listint_t **list, listint_t *node1, listint_t *node2);
/**
 *
 *
 *
 */


void cocktail_sort_list(listint_t **list)
{
	listint_t *start_position, *end_position, *mover, *bubble_up, *bubble_down;
	int start = 0, end = 0, moving = 0, min, max, limiter = 0;

	mover = *list;
	start_position = *list;
	while (mover->next != NULL)
	{
		mover = mover->next;
		end++;
	}
	printf("Start: %d End: %d\n", start, end);
	end_position = mover;
	while (start < (end - limiter))
	{
		mover = start_position;
		max = start_position->n;
		while (moving < end)
		{
			printf("Mover is bubling up! Max=%d\n", max);
			mover = mover->next;
			printf("Mover is now on: %d\n", mover->n);
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
		end_position = end_position->prev;
		end--;
		min = end_position->n;
		while (moving > (start + limiter))
		{
			printf("Mover is bubbling down! Min=%d\n", min);
			mover = mover->prev;
			printf("Mover is now on: %d\n", mover->n);
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
		start_position = start_position->next;
		start++;
		limiter++;
	}
}

void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
/*	listint_t *swapper = node1; */

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

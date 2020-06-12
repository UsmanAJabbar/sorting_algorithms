#include "sort.h"
#include <stdio.h>

void insertion_sort_list(listint_t **list)
{
	listint_t *second_elem, *temp, *stitch_front, *stitch_back;
	int swap_tick = 1;

	/*
	# We need to keep the address of what the second element->next was
	# pointing and also keep a list of what the first element->prev
	# was pointing at.

	# Once that's done, then, second_elem->next = first_elem
	# Tick the flag asserting that a swap has occured.
	# Then print the current status of the array and restart the loop.
	*/

	while (swap_tick == 1 && temp)
		for (temp = *list, swap_tick = 0; temp; temp = temp->next)
		{
			if (temp->n > temp->next->n) 	/* Being the swapped */
			{
				second_elem = temp->next; /* Picked up the bad element */

				/* Disconnecting before moving */
				stitch_front = second_elem->next; /* -> */
				stitch_back = second_elem->prev; /* <- */
				second_elem->prev->next = stitch_front;
				second_elem->next->prev = stitch_back;

				while (second_elem->n > temp->n)
				{
					if (temp->prev == NULL)
						break;
					temp = temp->prev;	
				}

				/* If the node's being inserted in the middle of the list */
				if (temp->prev != NULL)
				{
					temp->prev->next = second_elem;
					second_elem->next = temp;
					second_elem->prev = temp->prev;
					temp->prev = second_elem;
				}

				/* If the nodes becoming the head */
				else if (temp->prev == NULL)
				{	
					second_elem->prev = NULL;
					second_elem->next = temp;
					temp->prev = second_elem;
					*list = second_elem;
				}

				print_list(*list), swap_tick = 1;
			}
			if (swap_tick == 1)
				break;
		}
}

#include "sort.h"

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = *list;

	if (!temp || *temp->next)
		return;

	while (check != 0) 		/* Keep running until the checker function doesn't approve */
}

/* This function swaps two nodes */
void swap_list(listint_t *swap1, listint_t *swap2)
{
	listint_t *to_be_head, *to_be_tail, *rest_list;

	if (swap1 && swap2)
	{
		/* Find out whether or not the node being switched is */
		/* either a head or tail and handle them accordingly */

		/* If head and tails are the ones to be swapped */
		if (!swap1->prev && !swap2->next || !swap1->next && !swap2-prev)
		{
			printf("swap_list indentified that you're swapping a head and tail\n");

			/* Identify if swap1's the head and needs to become the tail */
			if (swap1->next) 		/*SWAP1's the head */
			{
				printf("Position 1 arg has been identified as the head\n");
				to_be_head = swap2, to_be_tail = swap1; /* Renaming */

				to_be_head->prev = to_be_tail;
				to_be_tail->next = to_be_head;
				to_be_head->next = NULL;
				to_be_tail->prev = NULL;
			}
			/* Else, swap2's the head and needs to become the tail */
			else
			{
				printf("Position 2 arg has been identified as the head\n");
				to_be_head = swap1, to_be_tail = swap2;

				to_be_head->prev = to_be_tail;
				to_be_tail->next = to_be_head;
				to_be_head->next = NULL;
				to_be_tail->prev = NULL;
			}
		}

		/* If swap1/swap2's the head */
		if (!swap1->prev || !swap2->prev)
		{
			printf("Either position 1 or position 2 arg has been identified as the head");
			if (!swap1->prev) /* Swap1->prev is NULL, making it the head */
			{
				printf("Position 1 arg has been identified as the head\n");
				to_be_head = swap2; /* Second element must become the head */
				swap1->prev = to_be_head; /* Old head->prev should now point to new head */
				rest_list = to_be_head->next; /* Keep a copy to the address of the rest of the list */
				to_be_head->next = swap1;
				to_be_head->prev = NULL;
				swap1->next = rest_list; /* Give the old head the address to the rest of the list */
			}

			else
			{
				printf("Position 2 arg has been identified as the head\n");
				to_be_head = swap1; /* Second element must become the head */
				swap2->prev = to_be_head; /* Old head->prev should now point to new head */
				rest_list = to_be_head->next; /* Keep a copy to the address of the rest of the list */
				to_be_head->next = swap2;
				to_be_head->prev = NULL;
				swap2->next = rest_list; /* Give the old head the address to the rest of the list */				
			}
		}

		/* If swap1/swap2's the tail */
		else if (swap1->next || swap2->next)
		{
			printf("Either position 1 or position 2 arg has been identified as the head");
			if (!swap1->next) /* Swap1->prev is NULL, making it the head */
			{
				printf("Position 1 arg has been identified as the tail\n");
				to_be_tail = swap2; /* Second element must become the head */
				swap1->prev = to_be_head; /* Old head->prev should now point to new head */
				rest_list = to_be_head->next; /* Keep a copy to the address of the rest of the list */
				to_be_head->next = swap1;
				to_be_head->prev = NULL;
				swap1->next = rest_list; /* Give the old head the address to the rest of the list */
			}

			else
			{
				printf("Position 2 arg has been identified as the tail\n");
				to_be_head = swap1; /* Second element must become the head */
				swap2->prev = to_be_head; /* Old head->prev should now point to new head */
				rest_list = to_be_head->next; /* Keep a copy to the address of the rest of the list */
				to_be_head->next = swap2;
				to_be_head->prev = NULL;
				swap2->next = rest_list; /* Give the old head the address to the rest of the list */
			}
		}


	}
}

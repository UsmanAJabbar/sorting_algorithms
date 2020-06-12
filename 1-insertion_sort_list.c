#include "sort.h"

void swapper(listint_t **list, listint_t *sorted);
/**
 *
 *
 *
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *sorted = *list;

	/* Well need to compare two nodes and the if a > b then b will swap
	// if a<b then we will compare b and c. b > c swap and c < a swap continue
	// swapping until in the lowest place for that node->n.
	*/
	while (sorted != NULL)
	{
		/* While we are not through the end of our list */
		temp = sorted->next;
		/* move one past the sorted section of the list */
		if (temp->n < sorted->n)
		{
			swapper(list, sorted);
		}
		else
			sorted = sorted->next;
	}
}



void swapper(listint_t **list, listint_t *sorted)
{
	listint_t *check_sorted, *temp = sorted->next;

/* First we are going to swap sorted and temp as this function is called when
temp->n is < sort->n in the above function*/
	sorted->next = temp->next;
	temp->next->prev = sorted;
       	temp->next = sorted;
	if (sorted->prev !=NULL)
	{
		sorted->prev->next = temp;
		temp->prev = sorted->prev;
	}
	sorted->prev = temp;
	print_list(*list); 

        if (temp->prev != NULL)
	{
		check_sorted = temp->prev;
		if (check_sorted->n > temp->n)
			swapper(list, check_sorted);
	}
	else
	{
		(void) check_sorted;
		(*list) = temp;
	}
}

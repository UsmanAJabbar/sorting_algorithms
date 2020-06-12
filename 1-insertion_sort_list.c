#include "sort.h"

/**
 *
 *
 *
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *check_sorted, *sorted = *list;

	/* Well need to compare two nodes and the is a > b then b will swap
	// is a<b then we will compare b and c. b > c swap and c < a swap continue
	// swapping until in the lowest place for that node->n.

	 if position->n > position->next->n then *tmp = postion->next
	*/
	while (sorted != NULL)
	{
		/* While we are not through the end of our list */
		temp = sorted->next;
		/* move one past the sorted section of the list */
		if (temp->n < sorted->n)
		{
			/* If temp.n is greater than sorted.n pull temp out of the list */
			sorted->next = temp->next;
			temp->next->prev = sorted;
			/* This stitches the sorten noted to temp next and temp is now free floating*/
			if (sorted->prev != NULL)
			{
				check_sorted = sorted;
				while (check_sorted->n > temp->n && check_sorted->prev != NULL)
					check_sorted = check_sorted->prev;
				if (check_sorted->prev == NULL)
				{
					temp->prev = NULL;
					temp->next = check_sorted;
					check_sorted->prev = temp;
				}
				else
				{
					temp->next = check_sorted->next;
					temp->next->prev = temp;
					temp->prev = check_sorted;
					check_sorted->next = temp;
				}
			}
			else
			{
				temp->prev = NULL;
				temp->next = sorted;
				sorted->prev = temp;
			}
			print_list(*list);
		}
		else
			sorted = sorted->next;
	}

}

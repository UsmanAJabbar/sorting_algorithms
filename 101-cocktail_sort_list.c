#include "sort.h"
#include <stdio.h>

void swap_node(listint_t *outter, listint_t *shake);
/**
 *
 *
 *
 */


void cocktail_sort_list(listint_t **list)
{
	listint_t *start_position, *end_position, *mover, *min_position, *max_position;
	int start = 0, end = 0, moving = 0;

	mover = *list;
	start_position = *list;
	while (mover->next != NULL)
	{
		mover = mover->next;
		end++;
	}
	printf("Start: %d End: %d\n", start, end);
	end_position = mover;
	while (start < end)
	{
		printf("Mover currently %d\n", mover->n);
		mover = start_position;
		printf("Mover re-assigned: %d\n", mover->n);
		min_position = start_position;
		printf("Min is: %d\n", min_position->n);

		while (moving < end && mover != NULL)
		{
			printf("In the while loop mover <= end\n");
			mover = mover->next;
			printf("Mover is at %d and min_pos is at %d\n", mover->n, min_position->n);
			if (mover->n < min_position->n)
			{
				min_position = mover;
				printf("Min_pos is now: %d\n", min_position->n);
			}
			printf("Moving: %d End:%d\n", moving, end);
			moving++;
		}
		printf("After first while loop\n");
		printf("Start_pos is at: %d and Min_pos is at:%d\n", start_position->n, min_position->n);
		swap_node(start_position, min_position);
		break;
		print_list(*list);
		start_position = start_position->next;
		start++;
		max_position = end_position;
		while(moving > start && mover != NULL)
		{
			mover = mover->prev;
			if (mover->n > max_position->n)
				max_position = mover;
			moving--;
		}
		printf("After second inner while loop\n");
		swap_node(end_position, max_position);
		print_list(*list);
		end_position = end_position->prev;
		end--;
		break;
	}

	printf("After main while loop\n");
}

void swap_node(listint_t *outter, listint_t *shake)
{
	listint_t *swapper = shake;

	swapper->next = shake->next;
	swapper->prev = shake->prev;
	printf("Swapper is at %d and Shake is at: %d\n", swapper->n, shake->n);

	shake->prev = outter->prev;
	shake->next = outter->next;
	printf("Shake next is now:%d\n", shake->next->n);

	outter->prev = swapper->prev;
	outter->next = swapper->next;
	printf("Outer prev is now: %d\n", outter->prev->n);
}

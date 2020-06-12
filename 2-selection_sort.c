#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - swaps the indexes in the array
 * until the array has been sorted
 * @array: input array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, flag, minindex, temp; 
	int minval;

	/* Keep a copy of where the min was found */
	/* Switch out the current index with array[jindex] */

	for (i = 0, flag = 0, minval = array[i]; i < size; i++, minval = array[i])
	{
		for (j = i + 1; array[j]; j++)
			if (array[j] < minval)
				minval = array[j], minindex = j, flag = 1;

		if (flag == 1)
		{
			temp = array[i]; /* Temp store val in array[i] */
			array[i] = minval; 	/* Replace array[i] with the minval found */
			array[minindex] = temp; /* Replace old array[i] with the index where el found */
			print_array(array, size); /* Print the current status of the array */
			flag = 0; /* Reset the flag for the next loop */
		}
	}
}

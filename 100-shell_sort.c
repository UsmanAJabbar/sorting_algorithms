#include "sort.h"
#include <stdio.h>

int check_ordered(int *array, size_t size);
/**
 *
 *
 */


void shell_sort(int *array, size_t size)
{
	size_t i, j, knuth = 1, done = 0;
	int temp;
	
	if (array == NULL || size <= 1)
		return;
	done = check_ordered(array, size);
	if (done == 1)
		return;
	while (1)
		if (((knuth * 3) + 1) < size)
			knuth = (knuth * 3) + 1;
		else
			break;
	while (knuth > 1)
	{
		printf("In the while loop, knuth=%ld\n", knuth);
		for (i = 0; i < j; i++)
		{
			printf("In the for loop\n");
			j = i + knuth;
			if (j < size)
			{
				printf("array[%ld] = %d and array[%ld] = %d\n", i, array[i], j, array[j]);
				if (array[i] > array[j])
				{
					printf("Swap o'clock\n");
					printf("i was %d and j was %d\n", array[i], array[j]);
					temp = array[i];
					array[i] = array[j];
					array[i] = temp;
					printf("i now is %d and j now is %d\n", array[i], array[j]);
					print_array(array, size);
				}
			}
			else
				break;
		}
		knuth = (knuth / 2);
	}
}

int check_ordered(int *array, size_t size)
{
	size_t i, ordered = 0;

	for (i = 0; i < (size - 1); i++)
	{
		if (array[i] < array[i+1])
			ordered = 1;
		else
			return (0);
	}
	return (ordered);
}

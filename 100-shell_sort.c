#include "sort.h"

//we get a titration window by running (n*3) + 1 until the next iteration will be > the len(array). 



void shell_sort(int *array, size_t size)
{
	int knuth = 1, done = 0, count = 0;

	if (array = NULL || size <=1)
		return;

	done = check_ordered(array, size);
	if (done == 1)
	   return;
// if it is not initially sorted we need out first knuth and multiplier count
	while (knuth < size)
	{
		knuth = (knuth * 3) + 1;
		count++;
	}
	knuth = (knuth / 3) - 1;

	swap(array, size, knuth, count);
}

int knuth(int count)
{
	int knuth = 1, i;
	//This function will be used to calculate the next knuth
	// value for each step down in the titration
	for (i = 0; i < count; i++)
		knuth = (knuth * 3) + 1;
	return (knuth);
}

void swap(int *array, size_t size, int knuth, int mul_count)
{
	int *values, *positions;
//the theory here is that we need to know how many checkers can be working
//through our array at a given time so we will malloc out two arrays
//the first on will hold the values of each knuth seperated position on our
//original array, and the second will hold the positions they came from so
//we can order them values and then put them back into the original array at the
//correct positions. then we will decrement the multiplies and run it again until
// multiplier hits zero.

	values = malloc(sizeof(int) * count);
	if (values == NULL)
		exit(MALLOC_FAILURE);
	positions = malloc(sizeof(int) * count);
	if (positions == NULL)
		exit(MALLOC_FAILURE);



}

int check_ordered(int *array, size_t size)
{
	size_t i, ordered = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] < array[i+1])
			ordered = 1;
		else
			return (0);
	}
	return (ordered);
}

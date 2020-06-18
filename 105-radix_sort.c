#include "sort.h"

/**
 * radix_sort - sorts an array given
 * @array: array given
 * @size: size of the array given
 * Return: Always Void
 */
void radix_sort(int *array, size_t size)
{
	int *new_array = malloc(sizeof(int) * size);
	int i, j, int_size = (int)size, exponent = 10;

	if (!array || !new_array || size < 2)
		return;

	while (sorted(array, size) != 0)
	{
		/* Generate when digits to sort */
		for (i = 0; i < int_size; i++)
			new_array[i] = (array[i] % exponent);

		/* Sort the digitized array */
		selection_sort(new_array, size);

		/* Put call on the numbers with those % values and put them */
		/* back into their arranged indexes accordingly. */
		for (i = 0, j = 0; i < int_size; i++)
			if ((array[i] % exponent) == (new_array[j]))
				if ((j == 0) || (array[i] != new_array[j - 1]))
					new_array[j] = array[i], i = -1, j++;

		/* Copy all of the contents from the new array into array */
		for (i = 0; i < int_size; i++)
			array[i] = new_array[i];

		/* Print the current status of the array and up the exponent */
		print_array(array, size), exponent *= 10;
	}
	free(new_array);
}

/**
 * sorted - checks if the list has been
 * sorted
 * @array: array given
 * @size: size
 * Return: 1 | 0
 */
int sorted(int *array, size_t size)
{
	int i;

	for (i = 0; i < (int)size - 1; i++)
		if (array[i] > array[i + 1])
			return (1);

	return (0);
}

/**
 * selection_sort - selection sort
 * @array: array
 * @size: size
 * Return: Always Void
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, flag, minindex, temp;
	int minval;

	if (!array)
		return;

	/* Keep a copy of where the min was found */
	/* Switch out the current index with array[jindex] */
	for (i = 0, flag = 0, minval = array[i]; i < size; i++, minval = array[i])
	{
		for (j = i + 1; array[j]; j++)
			if (array[j] < minval)
				minval = array[j], minindex = j, flag = 1;
		if (flag == 1)
		{
			temp = array[i], array[i] = minval, array[minindex] = temp;
			flag = 0;
		}
	}
}

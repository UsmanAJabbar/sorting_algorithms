#include "sort.h"

/**
 * quick_sort - being the first call from main,
 * quick_sort prepares the needed variables for
 * the upcoming function calls
 * @array: int array
 * @size: size of array
 * Return: Always void
 */
void quick_sort(int *array, size_t size)
{
	int int_size = size;
	sort(array, 0, int_size - 1, size);
}

/**
 * sort - function that sorts
 * an array by continously breaking
 * then into smaller pieces
 * @array: int array
 * @start: index start
 * @end: index end
 * @arraylen: exactly what it says dum dum
 * Return: Always void
 */
void sort(int *array, int start, int end, size_t arraylen)
{
	int pivotindex;

	if (start < end)
	{
		pivotindex = lomuto(array, start, end, arraylen);
		sort(array, start, pivotindex - 1, arraylen);
		sort(array, pivotindex + 1, end, arraylen);
	}
}

/**
 * lomuto - swaps and puts the pivot in
 * the right spot, then returns the index
 * where the pivot was placed.
 * @array: input array
 * @low: index where sorting should begin
 * @high: index where sorting should end
 * @arraylen: array len
 * Return: index of the pivot after being placed
 */
size_t lomuto(int *array, int low, int high, size_t arraylen)
{
	int j, i = (low - 1), pivot = array[high];

	for (j = low; j <= high - 1; j++)
		if (array[j] < pivot)
			i++, swap(&array[i], &array[j]), print_array(array, arraylen);

	swap(&array[i + 1], &array[high]), print_array(array, arraylen);
	return (i + 1);
}

/**
 * swap - takes care of the swapping
 * between two elements in an int array
 * @left: left element index to swap
 * @right: right element index to swap
 * Return: Always void
 */
void swap(int *left, int *right)
{
	int temp;

	if (left && right)
		temp = *left, *left = *right, *right = temp;
}

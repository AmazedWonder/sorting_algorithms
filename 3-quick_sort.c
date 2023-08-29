#include "sort.h"

/**
 * swap - function swaps the values of two integer
 * variables using pointers
 * @a: pointers to integers of variables to be swapped
 * @b: pointers to integers of variables to be swapped
 * Return: (void) Swaped int
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;/*storing the value of a in temp*/
	*a = *b;/*replacing the value of a with value of b.*/
	*b = temp;/*temp (the original value of a) is assigned to b*/
}
/**
 * partition - function is used to partition an array using pivot
 * @array:pointer to the array of integers
 * @low: integers representing indices of the subarray to be partitioned
 * @high: integers representing indices of the subarray to be partitioned
 * @size: size of array (size_t)
 * Return: index of pivote (int)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivt = array[high];
	int parti_i = low - 1, curr_i;

	for (curr_i = low; curr_i <= high; curr_i++)/* iterates from low to high*/
	{
		if (array[curr_i] <= pivt)
		{
			parti_i++;
			if (parti_i != curr_i)/*If they are not the same*/
			{
				swap(&array[parti_i], &array[curr_i]);
				print_array(array, size);
			}
		}
	}
	return (parti_i);
}
/**
 * lomuto_qsort - Sorting Recursively an Array
 * @array: pointer to the array of integers to be sorted
 * @low: The lowest value of the subarray to be sorted
 * @high: highest value of the subarray to be sorted
 * @size: Size of the array
 * Return: void
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)/*indicates more than one elem in subarray*/
	{
		i = partition(array, low, high, size);
		/*call sorts the subarray from low to i - 1*/
		lomuto_qsort(array, low, i - 1, size);
		/*recursive call sorts the subarray from i + 1 to high*/
		lomuto_qsort(array, i + 1, high, size);
	}
}
/**
 * quick_sort - function that serves as a wrapper for the
 * lomuto_qsort function using quick sort algorithm to sort array
 * @array: pointer to the array of integers
 * @size: size of the array.
 * Return: Sorted array (void)
 */
void quick_sort(int *array, size_t size)
{
	/*calls the lomuto_qsort function, passing the array*/
	/* 0 as the lower index, size - 1 as the higher index*/
	/*and size as the size of the array.*/
	lomuto_qsort(array, 0, size - 1, size);
}

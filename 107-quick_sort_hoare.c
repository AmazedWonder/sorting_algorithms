#include "sort.h"

/**
 * swap_eles - used to swap two elements in an array.
 * @array: a pointer to an array of integers to modify.
 * @l: index of the first element to swap, left item.
 * @r: index of the second element to swap, right item.
 */
void swap_eles(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * hoare_partition - using the Hoare partition scheme recursively divides
 * the array into smaller subarrays and sorts them based on the chosen
 * pivot element. The pivot element is used to partition the array into
 * two halves, with elements on the left side being smaller than the pivot
 * and elements on the right side being larger than the pivot. The process
 * is repeated until the array is completely sorted.
 * @array: pointer to array containing the sub-array.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The size/length of the array.
 */
void hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	i = low - 1;
	j = high + 1;
	while (TRUE)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
		{
			swap_eles(array, i, j);
			print_array(array, size);
		}
		else
		{
			break;
		}
	}
	hoare_partition(array, low, j - (j == high), size);
	hoare_partition(array, j - (j == high) + 1, high, size);
}

/**
 * quick_sort_hoare -checks the validity of the input array
 * and size, and then calls the hoare_partition function to
 * perform the actual sorting process using Hoare's partition scheme.
 * The partitioning step separates the array into two subarrays,
 * recursively sorting each subarray until the entire array is
 * sorted in ascending order.
 * @array: The array to sort.
 * @size: The length of array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if ((array != NULL) && (size > 1))
	{
		hoare_partition(array, 0, size - 1, size);
	}
}


#include "sort.h"

/**
 * top_down_merge - func used recursively as part of the merge sort algorithm
 * to merge smaller subarrays until the entire array is sorted
 * Merges two subarrays in ascending order
 * @array: The array to merge.
 * @array_c: The temporary array to store merged elements.
 * @l: starting index of the left subarray
 * @m: The ending index of the left subarray and starting index of
 * the right subarray
 * The mid-point of the split-array.
 * @r: The ending index of the right subarray,
 * right index of the split-array.
 */
void top_down_merge(int *array, int *array_c, size_t l, size_t m, size_t r)
{
	size_t c = l, d = m, e;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + l, m - l);
	printf("[right]: ");
	print_array(array + (m), r - m);
	for (e = l; e < r; e++)
	{
		if ((c < m) && ((d >= r) || (array_c[c] <= array_c[d])))
		{
			array[e] = array_c[c++];
		}
		else
		{
			array[e] = array_c[d++];
		}
	}
	printf("[Done]: ");
	print_array(array + l, r - l);
}

/**
 * split_merge - function sorts an array that has been split using the
 * merge sort algorithm.
 * Recursively splits and merges subarrays in ascending order.
 * @array: The splitted array.
 * @array_c: The temporary array.
 * @size: size/Length of the original array.
 * @l: left index of the split-array.
 * @r: right index of the split-array.
 */
void split_merge(int *array, int *array_c, size_t size, size_t l, size_t r)
{
	size_t i, mid;

	if ((r - l) <= 1)
		return;
	mid = (l + r) / 2;
	split_merge(array, array_c, size, l, mid);
	split_merge(array, array_c, size, mid, r);
	for (i = l; i <= r + (r == size ? -1 : 0); i++)
		array_c[i] = array[i];
	top_down_merge(array, array_c, l, mid, r);
}

/**
 * merge_sort - Sorts an array in ascending order using the
 * merge sort algorithm.
 * @array: The array to sort.
 * @size: The size/length of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *array_c = NULL;

	if (array != NULL)
	{
		array_c = malloc(sizeof(int) * size);
		if (array_c != NULL)
		{
			for (i = 0; i < size; i++)
				array_c[i] = array[i];
			split_merge(array, array_c, size, 0, size);
			free(array_c);
		}
	}
}

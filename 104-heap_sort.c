#include "sort.h"

/**
 * swap_eles - used to swap two elements in an array.
 * @array: a pointer to an array of integers to modify.
 * @l: index of the first element to swap, left item.
 * @r: index of the second element to swap, right item.
 */
void swap_eles(int *array, size_t l, size_t r)
{
	int temp;

	if (array != NULL)
	{
		temp = array[l];
		array[l] = array[r];
		array[r] = temp;
	}
}

/**
 * sifts_down - function is used to sift down an element in a
 * max-heap, ensuring that the element is in its correct position
 * by comparing it with its children and swapping if necessary
 * Moves the largest element in an array to its correct
 * sorted position in a max-heap sub-array.
 * @array: pointer to an array of ints representing the heap to sort.
 * @arr_size: The size/length of the array.
 * @size: The size/length of the max heap sub-array.
 * @pos: starting position to sift down from.
 * position of the largest element in the max heap sub-array.
 */
void sifts_down(int *array, int arr_size, int size, int pos)
{
	int j, child;

	j = pos;
	while (j < (size / 2))
	{
		child = (2 * j) + 1;
		if ((child < (size - 1)) && (array[child] < array[child + 1]))
			child++;
		if (array[j] >= array[child])
			return;
		swap_eles(array, j, child);
		print_array(array, arr_size);
		j = child;
	}
}

/**
 * build_max_heap - functin builds a max heap binary tree with given array
 * uses the sifts_down function to build a max-heap from the input array
 * @array: a pointer to an array of integers to convert to a max
 * heap binary tree.
 * @size: The size/length of the array.
 */
void build_max_heap(int *array, int size)
{
	/*(size / 2) - 1 sets the starting index for the loop*/
	/* to the last non-leaf node in the binary tree*/
	/*representation of the array*/
	int a;

	for (a = (size / 2) - 1; a >= 0; a--)
	{
		sifts_down(array, size, size, a);
	}
}

/**
 * heap_sort -  function uses the build_max_heap function to build a
 * max-heap from the input array and then repeatedly extracts the
 * maximum element from the heap and places it in its correct position
 * in the array.
 * The sifts_down function is used to maintain the heap property
 * during the extraction process
 * @array: The array to sort.
 * @size: The length of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i, n;

	build_max_heap(array, size);
	n = size;
	for (i = 0; i < (int)size; i++)
	{
		swap_eles(array, --n, 0);
		if (n != 0)
		{
			print_array(array, size);
			sifts_down(array, size, n, 0);
		}
	}
}

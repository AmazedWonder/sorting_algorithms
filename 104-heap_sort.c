#include "sort.h"

/**
 * heapify - function  perform a heapify operation on an array
 * recurrssive heapSort
 * @array: a pointer to an array of integers
 * @heap: an integer representing the size of the heap data
 * @i: an integer representing the index of the current element
 * @size: an integer representing the size of the array
 */

void heapify(int *array, int heap, int i, int size)
{
	int lar = i, left = 2 * i + 1;
	int right = 2 * i + 2, tmp;

	if (left < heap && array[left] > array[lar])
		lar = left;
	if (right < heap && array[right] > array[lar])
		lar = right;
	if (lar != i)
	{
		tmp = array[i], array[i] = array[lar], array[lar] = tmp;
		print_array(array, size);
		heapify(array, heap, lar, size);
	}
}

/**
 * heap_sort - function uses the heapify function to build
 * a max-heap from the input array and then repeatedly extracts
 * the maximum element from the heap to sort the array
 * @array: a pointer to an array of integers to sort
 * @size: size of array to sort
 */

void heap_sort(int *array, size_t size)
{
	/*size / 2 -1 sets the starting index for the heapify*/
	/* operation to the last non-leaf node in the binary tree*/
	/*representation of the array*/
	int i = size / 2 - 1, tmp;

	if (array == NULL || size < 2)
		return;
	for (; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		if (i > 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}

}

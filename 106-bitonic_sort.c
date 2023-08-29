#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - function swaps values of two integers in an array.
 * @a: pointer to first integer to swap.
 * @b: pointer to second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - function implements the bitonic merge
 * operation, which is a key step in the bitonic sort algorithm.
 * It recursively merges adjacent subarrays of the given array based
 * on the specified flow direction, swapping elements when necessary.
 * @array: a pointer to an array of integers to be merged
 * @size: The size of the array.
 * @start: starting index of the subarray to be merged
 * @seq: size of the subarray to be merged
 * @flow:  a character indicating the desired merge
 * flow direction (either 'UP' or 'DOWN').
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, step_size = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + step_size; i++)
		{
			if ((flow == UP && array[i] > array[i + step_size]) ||
					(flow == DOWN && array[i] < array[i + step_size]))
				swap_ints(array + i, array + i + step_size);
		}
		bitonic_merge(array, size, start, step_size, flow);
		bitonic_merge(array, size, start + step_size, step_size, flow);
	}
}

/**
 * bitonic_seq - function follows a divide-and-conquer approach to
 * generate bitonic sequences and perform the merging operation.
 * It recursively divides the subarray into smaller halves, processes
 * them in a specific merge flow direction, and then merges them back
 * together using the bitonic_merge function.
 * The printing statements provide visual feedback on the merging
 * process and the intermediate and final results.
 * @array: a pointer to an array of integers to be sorted.
 * @size: The size of the array.
 * @start: starting index of the subarray to be processed
 * starting index of a block of building bitonic sequence.
 * @seq: size of the subarray to be processed
 * @flow: a character indicating the desired merge flow direction
 * ('UP' or 'DOWN')
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *dir = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, dir);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, dir);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - function serves as an entry point to the bitonic
 * sort algorithm. It checks the validity of the input array and
 * size, and then calls the bitonic_seq function to perform the
 * actual sorting process.
 * The bitonic_seq function will recursively divide the array
 * into smaller subarrays and perform the bitonic merging until
 * the entire array is sorted in ascending order.
 * @array: pointer to array of integers.
 * @size: The size of the array.
 *
 * Description: prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}

#include "sort.h"

int gets_max(int *array, int size);
void radix_count_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * gets_max -  function scans through an array and finds the maximum
 * element by comparing each element with the current maximum value
 * and updating it if a larger element is found.
 * @array: pointer to an array of integers.
 * @size: size of the array.
 *
 * Return: The maximum integer value in the array.
 */
int gets_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_count_sort -  function implements radix sort by repeatedly using
 * counting sort on each digit of the elements in the array, starting
 * from the least significant digit to the most significant digit.
 * The count array is used for counting the occurrences of each
 * digit, and the buff array is used as a temporary buffer for
 * storing intermediate results during the sorting process.
 * @array: pointer to an array of integers to be sorted
 * @size: The size of the array.
 * @sig: significance of the current digit being considered to sort on.
 * @buff: temporary buffer array for storing intermediate results
 * of sorted array.
 *
 * Return: void
 */
void radix_count_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - function performs radix sort on the input
 * array by repeatedly calling the radix_count_sort function
 * with different significant digits. It uses a temporary
 * buffer array for intermediate results and prints the array
 * after each iteration
 * @array: a pointer to an array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Implements LSD radix sort algorithm and prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = gets_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_count_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}

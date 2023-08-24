#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints the current state or value of an array
 * Prints an array of integers
 * @array: pointer to the array of integers
 * @size: size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)/*array is not NULL and i is less than size*/
	{
		if (i > 0)/*means that it's not the first element being printed*/
			printf(", ");/*print comma*/
		printf("%d", array[i]);/* prints the value of array[i]*/
		++i;
	}
	printf("\n");
}

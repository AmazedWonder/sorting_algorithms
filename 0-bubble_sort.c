#include "sort.h"

/**
 *bubble_sort - Function sorts an array of int in ascending order
 *@array: array of numbers/pointer to the array of integers
 *@size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t pass_i, element_i;
	int temp;

	if (array == NULL  || size < 2)
		return;/*returns from the function*/
	for (pass_i = 0; pass_i < size - 1; pass_i++)/*controls the number of passes*/
	{/*loop compares adjacent elements of array/swaps them if in wrong order*/
		for (element_i = 0; element_i < size - pass_i - 1; element_i++)
		{/*it means elements are out of order*/
			if (array[element_i] > array[element_i + 1])
			{
				temp = array[element_i];/*swaps the elements*/
				array[element_i] = array[element_i + 1];
				array[element_i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}

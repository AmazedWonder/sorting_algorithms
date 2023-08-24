#include "sort.h"
/**
 * selection_sort - function sort an array of integers
 * in ascending order
 *@size:  the size of the array
 * @array: a pointer to the array of integers
 */
void selection_sort(int *array, size_t size)
{
	size_t pass_i, elem_i;
	int swap, flag = 0, track_elem;

	if (array == NULL)
		return;
	for (pass_i = 0; pass_i < size; pass_i++)
	{
		track_elem = pass_i;
		flag = 0;
		for (elem_i = pass_i + 1; elem_i < size; elem_i++)
		{
			if (array[track_elem] > array[elem_i])
			{
				track_elem = elem_i;
				flag += 1;
			}
		}
		swap = array[pass_i];
		array[pass_i] = array[track_elem];
		array[track_elem] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}

#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 * using shell sort that builds on the insertion sort algorithm
 * by repeatedly sorting the array with different gap values until
 * the gap becomes 0, resulting in a fully sorted array.
 * @array: a pointer to the array of integers to be sorted
 * @size: number of elements in the array
 **/

void shell_sort(int *array, size_t size)
{
	unsigned int  i, gap = 1, j;
	int tmp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	/*calculated using the formula gap = gap * 3 + 1*/
	/*until gap becomes larger than size / 3*/
	/* loop initializes gap value based on size of the array*/
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* loop performs the shell sort algorithm*/
	/*decreasing the value of gap after each iteration*/
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			/*current element is stored in the temp var*/
			/*In each iteration of the inner loop, the*/
			/*elements are shifted by gap positions to the right.*/
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		print_array(array, size);/*print the current state of the array*/
		/*gap value is divided by 3 to update the gap sequence for next iteration*/
		gap /= 3;
	}
}

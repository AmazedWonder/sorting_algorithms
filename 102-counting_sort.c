#include "sort.h"

/**
 * counting_sort - function counts sort on the input array by counting
 * the occurrences of each element, calculating cumulative counts,
 * and reconstructing the sorted array based on counts
 * @array: pointer to array to sort.
 * @size: The length of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_ele = NULL, *sorted_ele = NULL, max_val = 0;
	size_t i;

	if ((array == NULL) || (size < 2))
		return;
	for (i = 0; i < size; i++)
	{
		max_val = (array[i] > max_val ? array[i] : max_val);
		if (array[i] < 0)
			return;
	}
	count_ele = malloc(sizeof(int) * (max_val + 1));
	if (count_ele == NULL)
		return;
	sorted_ele = malloc(sizeof(int) * size);
	if (sorted_ele == NULL)
	{
		free(count_ele);
		return;
	}
	for (i = 0; i < (size_t)(max_val + 1); i++)
		count_ele[i] = 0;
	for (i = 0; i < size; i++)
		count_ele[array[i]]++;
	for (i = 1; i < (size_t)(max_val + 1); i++)
		count_ele[i] += count_ele[i - 1];
	print_array(count_ele, max_val + 1);
	for (i = size - 1; ; i--)
	{
		count_ele[array[i]]--;
		sorted_ele[count_ele[array[i]]] = array[i];
		if (i == 0)
			break;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_ele[i];
	free(sorted_ele), free(count_ele);
}

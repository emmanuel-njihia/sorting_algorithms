#include "sort.h"

/**
 * selection_sort - integer array are sorted by selection sort algorithm in ascending order
 * @array: sorted array
 * @size: array size
 */

void selection_sort(int *array, size_t size)

{
	size_t k, l, min_idx;
	int temp;

	if (!array || size < 2)
		return;
	for (k = 0; k < size - 1; k++)
	{
		min_idx = k;
		for (l = k + 1; l < size; l++)
		{
			if (array[l] < array[min_idx])
				min_idx = l;
		}
		if (min_idx != k)
		{
			temp = array[k];
			array[k] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}

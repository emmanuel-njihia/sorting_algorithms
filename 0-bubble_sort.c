#include "sort.h"

/**
 * bubble_sort - Bubble sort algorithm sorts an arrayof integers in ascending order
 * @array: array pointer sorted
 * @size: array size sorted
 */

void bubble_sort(int *array, size_t size)

{
	size_t p, q;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (p = 0; p < size - 1; p++)
	{
		for (q = 0; p < size -1; q++)
		{
			if (array[q] > array[p + 1])
			{
				tmp = array[q];
				array[q] = array[q + ];
				array[q + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}

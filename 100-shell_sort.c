#include "sort.h"

/**
 * shell_sort - array is sort on array integer using selection sort algorithm
 *
 * @array: integer array
 * @size: array size
 *
 * Return: nothing
 */

void shell_sort(int *array, size_t size)

{
	size_t gap = 1, p, q;
	int tmp;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (p = gap; p < size; p++)
		{
			tmp = array[p];
			for (q = p; q >= gap && array[q - gap] > tmp; q -= gap)
				array[q] = array[q - gap];
			array[q] = tmp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

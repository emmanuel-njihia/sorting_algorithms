#include "sort.h"

/**
 * get_max - 	maximum list value
 * @array: integer list
 * @size: array size
 *
 * Return: maximum integer
 */

int get_max(int *array, int size)

{
	int max, m;

	for (max = array[0], m = 1; m < size; m++)
	{
		if (array[m] > max)
			max = array[m];
	}

	return (max);
}

/**
 * counting_sort - count sort algorithm
 * @array: An array
 * @size: array size
 *
 * Description: counting array returned
 */

void counting_sort(int *array, size_t size)

{
	int *count, *sort, max, m;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sort);
		return;
	}

	for (m = 0; m < (max + 1); m++)
		count[m] = 0;
	for (m = 0; m < (int)size; m++)
		count[array[m]] += 1;
	for (m = 0; m < (max + 1); m++)
		count[m] += count[m - 1];
	print_array(count, max + 1);

	for (m = 0; m < (int)size; m++)
	{
		sort[count[array[m]] - 1] = array[m];
		count[array[m]] -= 1;
	}

	for (m = 0; m < (int)size; m++)
		array[m] = sort[m];

	free(sort);
	free(count);
}

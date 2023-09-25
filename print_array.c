#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - integer array printed
 *
 * @array: printed array
 * @size: @array elements liated
 */

void print_array(const int *array, size_t size)

{
	size_t y;

	y = 0;
	while (array && y < size)
	{
		if (y > 0)
			printf(", ");
		printf("%d", array[y]);
		++y;
	}
	printf("\n");
}

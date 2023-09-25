#include "sort.h"
#include <stdio.h>

#define UP 1
#define DOWN 0

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array
 * @a: swap integer 1
 * @b: swap integer 2
 */

void swap_ints(int *a, int *b)

{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: integer array
 * @size: array size
 * @start: sorting array in starting sequence
 * @seq: sort sequence size
 * @flow: sort in direction
 */

void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)

{
	size_t z, jump = seq / 2;

	if (seq > 1)
	{
		for (z = start; z < start + jump; z++)
		{
			if ((flow == UP && array[z] > array[z + jump]) ||
			    (flow == DOWN && array[z] < array[z + jump]))
				swap_ints(array + z, array + z + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: integer array
 * @size: array size
 * @start: bitonic sequnce in block building in starting index
 * @seq: bitonic sequence in block building size
 * @flow: bitonic in block sequence to sort in direction
 */

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)

{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order using the bitonic sort algorithm.
 * @array: integer array
 * @size: array size
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2)
 */

void bitonic_sort(int *array, size_t size)

{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}

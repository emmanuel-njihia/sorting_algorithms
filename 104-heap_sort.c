#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: integer 1 swap
 * @b: integer 2 swap
 */

void swap_ints(int *a, int *b)

{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - binary heap in binary tree
 * @array: binary tree integer array
 * @size: array/tree size
 * @base: base row index of tree
 * @root: binary tree root node
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)

{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - sort algorithm in sort heap array
 * @array: integer array
 * @size: array size
 * Description: heap sort down
 */

void heap_sort(int *array, size_t size)

{
	int d;

	if (array == NULL || size < 2)
		return;

	for (d = (size / 2) - 1; d >= 0; d--)
		max_heapify(array, size, size, d);

	for (d = size - 1; d > 0; d--)
	{
		swap_ints(array, array + d);
		print_array(array, size);
		max_heapify(array, size, d, 0);
	}
}

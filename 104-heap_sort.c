#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - swap 2 ints in array
 * @a: 1st in to swap.
 * @b: 2nd int to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpp;

	tmpp = *a;
	*a = *b;
	*b = tmpp;
}

/**
 * max_heapify - turn binary to complete tree.
 * @array: arrauy rep binary tree
 * @size: size of array
 * @base: index in base row of tree
 * @root: root node of tree
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t leftt, rightt, largee;

	leftt = 2 * root + 1;
	rightt = 2 * root + 2;
	largee = root;

	if (leftt < base && array[leftt] > array[largee])
		largee = leftt;
	if (rightt < base && array[rightt] > array[largee])
		largee = rightt;

	if (largee != root)
	{
		swap_ints(array + root, array + largee);
		print_array(array, size);
		max_heapify(array, size, base, largee);
	}
}

/**
 * heap_sort - sort array of int
 * @array: an array
 * @size: size of these array
 */
void heap_sort(int *array, size_t size)
{
	int ii;

	if (array == NULL || size < 2)
		return;

	for (ii = (size / 2) - 1; ii >= 0; ii--)
		max_heapify(array, size, size, ii);

	for (ii = size - 1; ii > 0; ii--)
	{
		swap_ints(array, array + ii);
		print_array(array, size);
		max_heapify(array, size, ii, 0);
	}
}

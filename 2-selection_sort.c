#include "sort.h"

/**
 * swap_ints - for swaping 2 int
 * @a: 1st element in swap
 * @b: 2nd elemnt in swap
 */
void swap_ints(int *a, int *b)
{
	int tmpp;

	tmpp = *a;
	*a = *b;
	*b = tmpp;
}

/**
 * selection_sort - sort array in asc order
 * @array: array of integers
 * @size: size of array.
 */
void selection_sort(int *array, size_t size)
{
	int *minn;
	size_t ii, jj;

	if (array == NULL || size < 2)
		return;

	for (ii = 0; ii < size - 1; ii++)
	{
		minn = array + ii;
		for (jj = ii + 1; jj < size; jj++)
			minn = (array[jj] < *minn) ? (array + jj) : minn;

		if ((array + ii) != minn)
		{
			swap_ints(array + ii, minn);
			print_array(array, size);
		}
	}
}

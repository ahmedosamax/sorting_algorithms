#include "sort.h"

/**
 * swap_ints - for swaping integr
 * @a: first elment
 * @b: second elemtn
 */
void swap_ints(int *a, int *b)
{
	int tmmpp;

	tmmpp = *a;
	*a = *b;
	*b = tmmpp;
}

/**
 * shell_sort - sorting array
 * @array: array
 * @size: size of array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gapp, ii, jj;

	if (array == NULL || size < 2)
		return;

	for (gapp = 1; gapp < (size / 3);)
		gapp = gapp * 3 + 1;

	for (; gapp >= 1; gapp /= 3)
	{
		for (ii = gapp; ii < size; ii++)
		{
			jj = ii;
			while (jj >= gapp && array[jj - gapp] > array[jj])
			{
				swap_ints(array + jj, array + (jj - gapp));
				jj -= gapp;
			}
		}
		print_array(array, size);
	}
}

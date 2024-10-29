#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - for swaping 2 int
 * @a: the 1st element to be swaped.
 * @b: The 2nd element to be swaped.
 */
void swap_ints(int *a, int *b)
{
	int tmpp;

	tmpp = *a;
	*a = *b;
	*b = tmpp;
}

/**
 * lomuto_partition - for lomuto_partition algo
 * @array: array of int
 * @size: size of array
 * @left: first index
 * @right: last index
 *
 * Return: final index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivott, abovee, beloww;

	pivott = array + right;
	for (abovee = beloww = left; beloww < right; beloww++)
	{
		if (array[beloww] < *pivott)
		{
			if (abovee < beloww)
			{
				swap_ints(array + beloww, array + abovee);
				print_array(array, size);
			}
			abovee++;
		}
	}

	if (array[abovee] > *pivott)
	{
		swap_ints(array + abovee, pivott);
		print_array(array, size);
	}

	return (abovee);
}

/**
 * lomuto_sort - for quicksort algo
 * @array: array of int
 * @size: size of the array
 * @left: 1st index
 * @right: last index
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partt;

	if (right - left > 0)
	{
		partt = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partt - 1);
		lomuto_sort(array, size, partt + 1, right);
	}
}

/**
 * quick_sort - sort element in asc order
 * @array: array of int
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

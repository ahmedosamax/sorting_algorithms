#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - swap 2 int
 * @a: 1st to be swaped
 * @b: 2nd to be swaped.
 */
void swap_ints(int *a, int *b)
{
	int tmpp;

	tmpp = *a;
	*a = *b;
	*b = tmpp;
}

/**
 * hoare_partition - order subset array
 * @array: an array of int
 * @size: size of the array
 * @left: first index
 * @right: last index
 * Return: final index.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivott, abovee, beloww;

	pivott = array[right];
	for (abovee = left - 1, beloww = right + 1; abovee < beloww;)
	{
		do {
			abovee++;
		} while (array[abovee] < pivott);
		do {
			beloww--;
		} while (array[beloww] > pivott);

		if (abovee < beloww)
		{
			swap_ints(array + abovee, array + beloww);
			print_array(array, size);
		}
	}

	return (abovee);
}

/**
 * hoare_sort - for quick sorting
 * @array: array of int
 * @size: size of array
 * @left: the first index
 * @right: the last index
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int partt;

	if (right - left > 0)
	{
		partt = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, partt - 1);
		hoare_sort(array, size, partt, right);
	}
}

/**
 * quick_sort_hoare - sort in element on asc order with quick sorrt
 * @array: array of integer
 * @size: size of integer
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

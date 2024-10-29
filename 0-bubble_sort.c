#include "sort.h"

/**
 * swap_ints - function for swaping.
 * @a: the first element to swap
 * @b: the second element to swap
 */
void swap_ints(int *a, int *b)
{
	int tmmpp;

	tmmpp = *a;
	*a = *b;
	*b = tmmpp;
}

/**
 * bubble_sort - sort ints in ascending order
 * @array: array of integer
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, lenn = size;
	bool bubbllyy = false;

	if (array == NULL || size < 2)
		return;

	while (bubbllyy == false)
	{
		bubbllyy = true;
		for (j = 0; j < lenn - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bubbllyy = false;
			}
		}
		lenn--;
	}
}

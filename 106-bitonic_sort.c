#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - swap 2 int in array
 * @a: 1st int.
 * @b: 2nd int
 */
void swap_ints(int *a, int *b)
{
	int tmpp;

	tmpp = *a;
	*a = *b;
	*b = tmpp;
}

/**
 * bitonic_merge - sort bitcoin seq.
 * @array: an array
 * @size: size of the array
 * @start: the first index
 * @seq: size of seq
 * @flow: the direction.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t ii, jumpp = seq / 2;

	if (seq > 1)
	{
		for (ii = start; ii < start + jumpp; ii++)
		{
			if ((flow == UP && array[ii] > array[ii + jumpp]) ||
			    (flow == DOWN && array[ii] < array[ii + jumpp]))
				swap_ints(array + ii, array + ii + jumpp);
		}
		bitonic_merge(array, size, start, jumpp, flow);
		bitonic_merge(array, size, start + jumpp, jumpp, flow);
	}
}

/**
 * bitonic_seq - convert array to betcoin seq
 * @array: An array
 * @size: size of array.
 * @start: the first index
 * @seq: the size of seq.
 * @flow: The direction
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cutt = seq / 2;
	char *strr = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, strr);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cutt, UP);
		bitonic_seq(array, size, start + cutt, cutt, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, strr);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - sort array in asc order
 * @array: An array
 * @size: size of array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}

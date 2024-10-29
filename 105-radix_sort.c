#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - get max value of array.
 * @array: an array
 * @size: size of array
 * Return: The max int.
 */
int get_max(int *array, int size)
{
	int maxx, ii;

	for (maxx = array[0], ii = 1; ii < size; ii++)
	{
		if (array[ii] > maxx)
			maxx = array[ii];
	}

	return (maxx);
}

/**
 * radix_counting_sort - sort digit of int
 * @array: an array
 * @size: size of the array
 * @sig: the digit to sort on
 * @buff: buffer to store
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int countt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t ii;

	for (ii = 0; ii < size; ii++)
		countt[(array[ii] / sig) % 10] += 1;

	for (ii = 0; ii < 10; ii++)
		countt[ii] += countt[ii - 1];

	for (ii = size - 1; (int)ii >= 0; ii--)
	{
		buff[countt[(array[ii] / sig) % 10] - 1] = array[ii];
		countt[(array[ii] / sig) % 10] -= 1;
	}

	for (ii = 0; ii < size; ii++)
		array[ii] = buff[ii];
}

/**
 * radix_sort - sort array
 * @array: An array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int maxx, sigg, *bufff;

	if (array == NULL || size < 2)
		return;

	bufff = malloc(sizeof(int) * size);
	if (bufff == NULL)
		return;

	maxx = get_max(array, size);
	for (sigg = 1; maxx / sigg > 0; sigg *= 10)
	{
		radix_counting_sort(array, size, sigg, bufff);
		print_array(array, size);
	}

	free(bufff);
}

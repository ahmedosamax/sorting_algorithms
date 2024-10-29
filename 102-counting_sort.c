#include "sort.h"

/**
 * get_max - get max value of int
 * @array: array
 * @size: size of array
 * Return: The max int in array.
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
 * counting_sort - sorting array
 * @array: array.
 * @size: size of the array
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *countt, *sortedd, maxx, ii;

	if (array == NULL || size < 2)
		return;

	sortedd = malloc(sizeof(int) * size);
	if (sortedd == NULL)
		return;
	maxx = get_max(array, size);
	countt = malloc(sizeof(int) * (maxx + 1));
	if (countt == NULL)
	{
		free(sortedd);
		return;
	}

	for (ii = 0; ii < (maxx + 1); ii++)
		countt[ii] = 0;
	for (ii = 0; ii < (int)size; ii++)
		countt[array[ii]] += 1;
	for (ii = 0; ii < (maxx + 1); ii++)
		countt[ii] += countt[ii - 1];
	print_array(countt, maxx + 1);

	for (ii = 0; ii < (int)size; ii++)
	{
		sortedd[countt[array[ii]] - 1] = array[ii];
		countt[array[ii]] -= 1;
	}

	for (ii = 0; ii < (int)size; ii++)
		array[ii] = sortedd[ii];

	free(sortedd);
	free(countt);
}

#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - sort integer.
 * @subarr: subbary of int
 * @buff: buffer to store the sub array
 * @front: the first index in array
 * @mid: the mid index in array
 * @back: the last index in array
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t ii, jj, kk = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (ii = front, jj = mid; ii < mid && jj < back; kk++)
		buff[kk] = (subarr[ii] < subarr[jj]) ? subarr[ii++] : subarr[jj++];
	for (; ii < mid; ii++)
		buff[kk++] = subarr[ii];
	for (; jj < back; jj++)
		buff[kk++] = subarr[jj];
	for (ii = front, kk = 0; ii < back; ii++)
		subarr[ii] = buff[kk++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - merge sorting with rec
 * @subarr: subarray to be sorted
 * @buff: buff to store sorted result
 * @front: 1st index of subarray
 * @back: last index of subarray
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t midd;

	if (back - front > 1)
	{
		midd = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, midd);
		merge_sort_recursive(subarr, buff, midd, back);
		merge_subarr(subarr, buff, front, midd, back);
	}
}

/**
 * merge_sort - sorting array of int
 * @array: array of int
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *bufff;

	if (array == NULL || size < 2)
		return;

	bufff = malloc(sizeof(int) * size);
	if (bufff == NULL)
		return;

	merge_sort_recursive(array, bufff, 0, size);

	free(bufff);
}

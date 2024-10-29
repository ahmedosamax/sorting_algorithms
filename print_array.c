#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - function for printing array
 * @array: the array we want to print
 * @size: umber of elements
 */
void print_array(const int *array, size_t size)
{
	size_t ii;

	ii = 0;
	while (array && ii < size)
	{
		if (ii > 0)
			printf(", ");
		printf("%d", array[ii]);
		++ii;
	}
	printf("\n");
}

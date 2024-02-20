#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * selection_sort - sort an array of integers using selection sort
 * name - Bruno  Owino
 * email - brunookoth44@gmail.com
 * @array: the array to order
 * @size: the siz of the array to order
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i = 0, j = 0, smallest = 0;
	int *swap = NULL;

	if (!array || size < 2)
		return;
	for (; i < size; i++)
	{
		smallest = i;
		swap =  malloc(sizeof(int) * 1);
		*swap = *(array + i);
		for (j = i + 1; j < size; j++)
		{
			if (*(array + j) < *(array + smallest))
			{
				smallest = j; 
			}
		}
		if (i < smallest)
		{
		*(array + i) = *(array + smallest);
		*(array + smallest) = *swap;
		free(swap);
		print_array(array, size);
		}
		else
			free(swap);
	}
}

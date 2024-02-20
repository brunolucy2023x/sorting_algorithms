#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @aa: The first integer to swap.
 * @bb: The second integer to swap.
 */
void swap_ints(int *aa, int *bb)
{
	int temp;

	temp = *aa;
	*aa = *bb;
	*bb = temp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, leen = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < leen - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		leen--;
	}
}

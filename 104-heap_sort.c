#include "sort.h"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
/**
* sift_down - fixes a heap
* @array: the heap to be fixed
* @root: root of heap
* name - Bruno  Owino
* email - brunookoth44@gmail.com
* @end: ;ast index of the heap
* @size: size of the array
*/
void sift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t left, right, swap;
	int temp;

	while ((left = (2 * root) + 1) <= end)
	{
		swap = root;
		right = left + 1;
		if (array[swap] < array[left])
			swap = left;
		if (right <= end && array[swap] < array[right])
			swap = right;
		if (swap == root)
			return;
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}

/**
* make_heap - makes a heap from an unsorted array
* @array: array to turn into a heap
* @size: size of the array
*
* Return: void
*/
void make_heap(int *array, size_t size)
{
	size_t parent;

	for (parent = ((size - 1) - 1) / 2; 1; parent--)
	{
		sift_down(array, parent, size - 1, size);
		if (parent == 0)
			break;
	}
}

/**
* heap_sort - sorts an array of ints in ascending order w/ the Heap sort algo
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;
	make_heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}

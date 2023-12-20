#include "sort.h"
#include <stdio.h>
/**
 * swap_numb - swaps numbers
 *
 * @arr: input array
 * @a: first index
 * @b: second index
 * Return: none
 */
void swap_numb(int *arr, int a, int b)
{
  arr[a] = arr[a] + arr[b];
  arr[b] = arr[a] - arr[b];
  arr[a] = arr[a] - arr[b];
}

/**
 * recur_heap - recursion that builds max heap tree
 *
 * @arr: input array
 * @i: index 
 * @size: size of array
 * @limit: limit of array
 * Return: none
 */
void recur_heap(int *arr, int i, size_t size, int limit)
{
  int big;
  int i2;

  i2 = i * 2;

  if (i2 + 2 < limit)
    {
      recur_heap(arr, i2 + 1, size, limit);
      recur_heap(arr, i2 + 2, size, limit);
    }

  if (i2 + 1 >= limit)
    return;

  if (i2 + 2 < limit)
    big = (arr[i2 + 1] > arr[i2 + 2]) ? (i2 + 1) : (i2 + 2);
  else
    big = i2 + 1;

  if (arr[i] < arr[big])
    {
      swap_numb(arr, i, big);
      print_array(arr, size);
      recur_heap(arr, big, size, limit);
    }
}

/**
 * heap_sort - sorts array in ascending
 * order using the Heap sort algorithm
 *
 * @array: input
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
  int j;
  size_t limit;

  if (!array || size == 0)
    return;

  j = 0;
  limit = size;

  while (limit > 1)
    {
      recur_heap(array, j, size, limit);
      if (array[j] >= array[limit - 1])
	{
	  swap_numb(array, j, limit - 1);
	  print_array(array, size);
	}
      limit--;
    }
}

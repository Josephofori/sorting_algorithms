#include "sort.h"

/**
 * bubble_sort - function to sort an array
 * of integers in ascending order using the
 * Bubble sort algorithm
 *
 * @array: input arrray
 * @size: array size
 * Return: no return
 */
void bubble_sort(int *array, size_t size)
{
  size_t i, n;
  int temp, swap;

  for (n = size, swap = 1; n > 0 && swap; n--)
    {
      swap = 0;
      for (i = 0; (i + 1) < n; i++)
	{
	  if (array[i] > array[i + 1])
	    {
	      temp = array[i + 1];
	      array[i + 1] = array[i];
	      array[i] = temp;
	      print_array(array, size);
	      swap = 1;
	    }
	}
    }
}

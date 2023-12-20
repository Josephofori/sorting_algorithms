#include "sort.h"
/**
 * quick_sort - function which sort an array
 * of integers in ascending order with the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
  _qsort(array, 0, size - 1, size);
}
/**
 * _qsort - auxiliar function for the
 * quick_sort function
 * @a: arrray input
 * @low: index for first element
 * @high: index for last element
 * @size: size of array
 * Return: none
 */
void _qsort(int *a, int low, int high, int size)
{
  int p, w, i;
  int temp;

  if (low < high)
    {
      p = high;
      w = low;
      for (i = low; i < high; i++)
	{
	  if (a[i] < a[p])
	    {
	      if (i != w)
		{
		  temp = a[i];
		  a[i] = a[w];
		  a[w] = temp;
		  print_array(a, size);
		}
	      w++;
	    }
	}
      if (w != p && a[w] != a[p])
	{
	  temp = a[w];
	  a[w] = a[p];
	  a[p] = temp;
	  print_array(a, size);
	}
      _qsort(a, low, w - 1, size);
      _qsort(a, w + 1, high, size);
    }
}

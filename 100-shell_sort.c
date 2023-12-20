#include "sort.h"
/**
 * shell_sort - function which sorts array
 * of integers in ascending order with the
 * Shell sort algorithm
 *
 * @array: arrray input
 * @size: size of array
 * Return: none
 */
void shell_sort(int *array, size_t size)
{
  size_t m = 1;

  while (m < size)
    m = (m * 3) + 1;

  while ((m = (m - 1) / 3) > 0)
    _shsort(array, size, m);
}
/**
 * _shsort - auxiliar function for
 * shell_sort function
 * @a: arrray input
 * @size: size of array
 * @n: intervale
 * Return: none
 */
void _shsort(int *a, int size, int n)
{
  int temp, i, j;

  for (i = 0; (i + n) < size; i++)
    {
      for (j = i + n; (j - n) >= 0; j = j - n)
	{
	  if (a[j] < a[j - n])
	    {
	      temp = a[j];
	      a[j] = a[j - n];
	      a[j - n] = temp;
	    }
	}
    }
  print_array(a, size);
}

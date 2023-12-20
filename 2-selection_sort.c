#include "sort.h"

/**
 * selection_sort - sorts array of integers in
 * ascending order using the Selection sort
 * algorithm
 *
 * @array: array input of integers
 * @size: size of array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
  int temp;
  size_t i, j, me;

  for (i = 0; i < size; i++)
    {
      me = i;
      for (j = i + 1; j < size; j++)
	{
	  if (array[me] > array[j])
	    me = j;
	}

      if (i != me)
	{
	  temp = array[i];
	  array[i] = array[me];
	  array[me] = temp;
	  print_array(array, size);
	}
    }
}

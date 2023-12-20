#include "sort.h"
/**
 * counting_sort -Sorts array of integers
 * in ascending order with the
 * Counting sort algorithm
 * @array: array
 * @size: size of array
 * Return: none
 */
void counting_sort(int *array, size_t size)
{
  int x, j;
  int *buff, *a;

  if (size < 2)
    return;

  for (x = j = 0; j < (int)size; j++)
    if (array[j] > x)
      x = array[j];

  buff = malloc(sizeof(int) * (x + 1));
  if (!buff)
    return;

  for (j = 0; j <= x; j++)
    buff[j] = 0;
  for (j = 0; j < (int)size; j++)
    buff[array[j]] += 1;
  for (j = 1; j <= x; j++)
    buff[j] += buff[j - 1];

  print_array(buff, (x + 1));
  a = malloc(sizeof(int) * (size + 1));

  if (!a)
    {
      free(buff);
      return;
    }
  for (j = 0; j < (int)size; j++)
    {
      a[buff[array[j]] - 1] = array[j];
      buff[array[j]] -= 1;
    }

  for (j = 0; j < (int)size; j++)
    array[j] = a[j];

  free(buff);
  free(a);
}

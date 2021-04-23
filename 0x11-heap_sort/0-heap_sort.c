#include "sort.h"
/**
 * _swap - swaps 
 * @a: integer to swap
 * @b: integer to swap
 */
void _swap(int *a, int *b)
{
    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
}

/**
 * head - turns an array into a max heap
 * @array: array of integers to heapify
 * @idx: current given index within array
 * @size: size of the array
 * @len: size to use as boundaries
 */
void head(int *array, int idx, int size, int len)
{
    int left = (idx * 2) + 1;
    int right = (idx * 2) + 2;
    int max = idx;

    if (left > 0 && left < len && array[left] > array[max])
    {
        max = left;
    }
    if (right > 0 && right < len && array[right] > array[max])
    {
        max = right;
    }
    if (max != idx)
    {
        _swap(array + max, array + idx);
        print_array(array, size);
        head(array, max, size, len);
    }
}
/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 * sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i = (size / 2) - 1;
    int j = size - 1;

    while (i >= 0)
    {
        head(array, i, size, size);
        i--;
    }

    while (j > 0)
    {
        _swap(array + j, array);
        print_array(array, size);
        head(array, 0, size, j);
        j--;
    }
}

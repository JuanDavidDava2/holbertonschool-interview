#include "sort.h"

/**
 * radix_sort - Radix sort
 * @A: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *A, size_t size)
{
    int min = INT_MIN, *B = NULL;
    size_t i = 0;
    long digital_exponent;

    if (!A || size < 2)
        return;
    B = malloc(sizeof(*B) * size);
    if (!B)
        return;
    for (i = 0; i < size; i++)
        min = A[i] > min ? A[i] : min;
    for (digital_exponent = 1; min / digital_exponent > 0; digital_exponent *= RADIX)
    {
        count_sort(A, size, B, digital_exponent);
        print_array(A, size);
    }
    free(B);
}

/**
 * count_sort - count sort
 * @A: array to sort
 * @size: size of array
 * @B: malloced temp array
 * @digital_exponent: current  digital_exponent
 * Return: if array changed
 */
int count_sort(int *A, ssize_t size, int *B, long digital_exponent)
{
    ssize_t i;
    int count[RADIX] = {0}, res = 0;

    for (i = 0; i < size; i++)
        count[(A[i] / digital_exponent) % RADIX]++, B[i] = 0;
    for (i = 1; i < RADIX; i++)
        count[i] += count[i - 1];
    for (i = size - 1; i >= 0; i--)
        B[--count[(A[i] / digital_exponent) % RADIX]] = A[i];
    for (i = 0; i < size; i++)
        A[i] = B[i];
    return (res);
}
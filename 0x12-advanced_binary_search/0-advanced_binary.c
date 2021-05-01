#include "search_algos.h"

/**
 * advanced_binary - function that searches for
 * a value in a sorted array of integers.
 *
 * @array: the given data
 * @size: size of the data
 * @value: the given value to be searched
 *
 * Return:  the j of the first occurrence
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t i = 0, j = 0, res = 0;
    int tmp = 1;

    if (!array)
        return (-1);

    printf("Searching in array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i == size - 1)
            printf("\n");
        else
            printf(", ");
    }

    res = (size - 1) / 2;
    if (array[res] == value)
    {
        if (size == 1 || array[res - 1] < value)
            return (res);
    }
    else if (size == 1)
    {
        return (-1);
    }
    if (array[res] < value)
    {
        j += res + 1, array += res + 1;
        if (size % 2 != 0)
            res--;
    }
    res++;
    tmp = advanced_binary(array, res, value);
    if (tmp != -1)
        return (tmp + j);
    return (-1);
}


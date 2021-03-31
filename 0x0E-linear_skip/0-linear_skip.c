#include "search.h"

/**
 * linear_skip - Function to searches a value in a sorted skip list of int.
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 * Return: Node with the value or null.
 **/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *express = NULL, *last = NULL;

	while (current)
	{
		express = current->express;

		if (!express)
		{
			last = current;
			while (last->next)
				last = last->next;
			printf("Value found between indexes [%ld] and [%ld]\n",
				   current->index,
				   last->index);
		}
		else
		{
			printf("Value checked at index [%ld] = [%d]\n", express->index, express->n);
			if (value > express->n)
			{
				current = express;
				continue;
			}
			else
				printf("Value found between indexes [%ld] and [%ld]\n",
					   current->index,
					   express->index);
		}

		while (current)
		{
			printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
			if (value == current->n)
				return (current);

			current = current->next;
		}
	}

	return (NULL);
}

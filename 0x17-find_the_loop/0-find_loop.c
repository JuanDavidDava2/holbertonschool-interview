#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: head
 * Return: node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first, *last;

	first = head;
	last = first;
	while (first && last && last->next)
	{
		first = first->next;
		last = last->next->next;
		if (first == last)
		{
			first = head;
			while (first && last)
			{
				if (first == last)
					return (first);
				first = first->next;
				last = last->next;
			}
		}
	}
	return ('\0');
}

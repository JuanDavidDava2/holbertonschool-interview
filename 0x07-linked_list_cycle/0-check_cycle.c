#include "lists.h"
/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: list to check.
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
    listint_t *hare, *t;

    hare = t = list;

    while (hare && hare->next)
    {
        hare = hare->next->next;
        t = t->next;
        if (hare == t)
            return (1);
    }
    return (0);
}
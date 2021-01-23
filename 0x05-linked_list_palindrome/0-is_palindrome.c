#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to the head.
 * Return: 0 if it is not a palindrome, 1 if is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *actual = *head;
    int i, j = 0;
	int array[2048];

	if (*head == NULL || actual->next == NULL || head == NULL)
		return (1);

	for (i = 0; actual != NULL; i++)
	{
		array[i] = actual->n;
		actual = actual->next;
	}
	i--;
	for (; j <= i; j++, i--)
	{
		if (array[j] != array[i])
			return (0);
	}
	return (1);
}

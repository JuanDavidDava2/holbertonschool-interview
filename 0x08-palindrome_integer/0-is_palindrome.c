#include "palindrome.h"
/**
 * is_palindrome - Function to check palindromes
 * @n: Number to be checked
 * Return: 1 or 0
 */

int is_palindrome(unsigned long n)
{
	unsigned long num, count = 0;

	num = n;

	while (num != 0)
	{
		count = count * 10;
		count = count + num % 10;
		num = num / 10;
	}
	if (n == count)
		return (1);
	else
		return (0);
}
#include "palindrome.h"


/**
 * is_palindrome - checks if unsigned integer is palidrome
 *
 * @n: unsigned integer to be checked
 * Return: 1 if is palindrome 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long rev_n, cloN;

	rev_n = 0;
	cloN = n;

	while (n != 0)
	{
		rev_n = rev_n * 10 + n % 10;
		n /= 10;
	}
	if (rev_n == cloN)
		return (1);
	else
		return (0);
}

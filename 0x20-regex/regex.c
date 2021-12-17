#include "regex.h"

/**
 * regex_match - checks if a given string matches a pattern
 * @str: is the string to check
 * @pattern: is the pattern reference to compare
 * Return: 1 if the pattern matches the string or 0 if ti doesn't
 */
int regex_match(char const *str, char const *pattern)
{
	int dot_char = 0, wild_char = 0;

	if (!str || !pattern)
		return (0);

	dot_char = *str && (*str == *pattern || *pattern == '.');
	wild_char = *(pattern + 1) == '*';

	if (!*str && !wild_char)
	{
		if (!*pattern)
			return (1);
		return (0);
	}

	if (dot_char && wild_char)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (dot_char && !wild_char)
		return (regex_match(str + 1, pattern + 1));
	else if (wild_char)
		return (regex_match(str, pattern + 2));

	return (0);
}

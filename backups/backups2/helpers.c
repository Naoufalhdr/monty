#include "monty.h"

/**
 * _isdigit - checks if a given string is an integer.
 * @str: the string to be tested.
 *
 * Return: 1 if is an integer; otherwise 0.
 */
int _isdigit(char *str)
{
	int i;

	if (str[0] == '-')
		str++;

	for (i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			continue;
		else
			return (0);
	}

	return (1);
}

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
/**
 * _stack - Sets the execution mode to "stack".
 * @head: a double pointer to the stack/queue data structure (not used).
 * @line_number: The current line number being executed.
 */
void _stack(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;

	mode = "stack";
}

/**
 * _queue - Sets the execution mode to "queue".
 * @head: a double pointer to the stack/queue data structure (not used).
 * @line_number: The current line number being executed.
 */
void _queue(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;

	mode = "queue";
}

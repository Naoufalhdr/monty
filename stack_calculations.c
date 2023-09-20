#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @top: A pointer to the top of the stack.
 * @l_num: The current line number being executed.
 */
void add(stack_t **top, unsigned int l_num)
{
	if (*top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L<%u>: can't add, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n += (*top)->n;
	pop(top, l_num);
}

/**
 * sub - Adds the top two elements of the stack.
 * @top: A pointer to the top of the stack.
 * @l_num: The current line number being executed.
 */
void sub(stack_t **top, unsigned int l_num)
{
	if (*top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L<%u>: can't sub, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n -= (*top)->n;
	pop(top, l_num);
}

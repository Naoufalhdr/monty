#include "monty.h"

/**
 * nop - doesn't do anything.
 * @top: A pointer to the top of the stack.
 * @l_num: The current line number being executed.
 */
void nop(stack_t **top, unsigned int l_num)
{
	(void) l_num;
	(void) *top;
}

/**
 * swap - swaps the top two elements of the stack.
 * @top: A pointer to the top of the stack.
 * @l_num: The current line number being executed.
 */
void swap(stack_t **top, unsigned int l_num)
{
	int temp;

	if (*top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L<%u>: can't swap, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->n;
	(*top)->n = (*top)->prev->n;
	(*top)->prev->n = temp;
}

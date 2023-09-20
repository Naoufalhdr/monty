#include "monty.h"

/**
 * nop - doesn't do anything.
 * @top: A pointer to the top of the stack.
 * @line_number: The current line number being executed.
 */
void nop(stack_t **top, unsigned int line_number)
{
	(void) line_number;
	(void) *top;
}

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
 * sub -  subtracts the top element of the stack from
 *        the second top element of the stack.
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

/**
 * divide - divides the second top element of the stack by
 *          the top element of the stack.
 * @top: A pointer to the top of the stack.
 * @l_num: The current line number being executed.
 */
void divide(stack_t **top, unsigned int l_num)
{
	if (*top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L<%u>: can't div, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->n == 0)
	{
		fprintf(stderr, "L<%u>: division by zero\n", l_num);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n /= (*top)->n;
	pop(top, l_num);
}

/**
 * mul - multiplies the second top element of the stack with
 *       the top element of the stack.
 * @top: A pointer to the top of the stack.
 * @l_num: The current line number being executed.
 */
void mul(stack_t **top, unsigned int l_num)
{
	if (*top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L<%u>: can't mul, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n *= (*top)->n;
	pop(top, l_num);
}

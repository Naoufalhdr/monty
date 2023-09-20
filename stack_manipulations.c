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

/**
 * pstr - prints the string starting at the top of the stack.
 * @top: A pointer to the top of the stack.
 * @l_num: The current line number being executed.
 */
void pstr(stack_t **top, unsigned int l_num)
{
	stack_t *current;
	(void) l_num;

	if (*top == NULL)
		printf("\n");

	current = *top;
	while (current && (current->n > 0 && current->n <= 127))
	{
		printf("%c", current->n);
		current = current->prev;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top.
 * @top: A pointer to the top of the stack.
 * @l_num: The current line number being executed.
 */
void rotl(stack_t **top, unsigned int l_num)
{
	stack_t *current, *prev;
	int temp;
	(void) l_num;

	current = prev = *top;
	while (current->prev != NULL)
	{
		current = current->prev;
		temp = prev->n;
		prev->n = current->n;
		current->n = temp;
		prev = prev->prev;
	}
}

/**
 * rotr - rotates the stack to the bottom.
 * @top: A pointer to the top of the stack.
 * @l_num: The current line number being executed.
 */
void rotr(stack_t **top, unsigned int l_num)
{
	stack_t *current;
	(void) l_num;

	current = *top;
	while (current->prev != NULL)
		current = current->prev;

	push(top, l_num, current->n);
	current->next->prev = NULL;
	free(current);
}

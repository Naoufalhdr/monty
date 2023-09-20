#include "monty.h"

/**
 * push - pushes an element onto the stack.
 * @top: a pointer to the top of the stack.
 * @line_number: the current line number being executed.
 * @data: the integer to push onto the stack.
 */
void push(stack_t **top, unsigned int line_number, int data)
{
	stack_t *new_node;
	(void) line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		flag = 1;
		return;
	}

	new_node->n = data;
	new_node->next = NULL;

	new_node->next = NULL;

	if (*top == NULL)
	{
		*top = new_node;
		new_node->prev = NULL;
		return;
	}

	(*top)->next = new_node;
	new_node->prev = *top;
	*top = new_node;
}

/**
 * pall - prints all elements of the stack.
 * @top: a pointer to the top of the stack.
 * @line_number: is the current line number being executed.
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *current;
	(void) line_number;

	if (*top == NULL || line_number == 0)
		return;

	current = *top;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}

/**
 * pint - prints the value at the top of the stack.
 * @top: a pointer to the top of the stack.
 * @line_num: is the current line number being executed.
 */
void pint(stack_t **top, unsigned int line_num)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L<%u>: can't pint, stack empty\n", line_num);
		flag = 1;
		return;
	}

	printf("%d\n", (*top)->n);
}

/**
 * pop - removes the top element of the stack.
 * @top: a pointer to the top of the stack.
 * @line_num: is the current line number being executed.
 */
void pop(stack_t **top, unsigned int line_num)
{
	stack_t *current;

	if (*top == NULL)
	{
		fprintf(stderr, "L<%u>: can't pop an empty stack\n", line_num);
		flag = 1;
		return;
	}

	current = *top;
	*top = (*top)->prev;

	free(current);
}

/**
 * free_stack - Frees a stack of nodes.
 * @top: A pointer to the top (head) of the stack.
 */
void free_stack(stack_t **top)
{
	stack_t *current;

	if (top == NULL)
		return;

	current = *top;
	while (current != NULL)
	{
		current = current->prev;
		free(*top);
		*top = current;
	}
}

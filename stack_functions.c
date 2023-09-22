#include "monty.h"

/**
 * push - pushes an element onto the stack/queue.
 * @head: a pointer to the head of the stack/queue.
 * @line_number: the current line number being executed.
 * @data: the integer to push onto the stack/queue.
 */
void push(stack_t **head, unsigned int line_number, int data)
{
	(void) line_number;

	/* Stack mode (LIFO) */
	if (strcmp(mode, "stack") == 0)
		add_node_begin(head, data);

	/* Queue mode (FIFO) */
	else if (strcmp(mode, "queue") == 0)
		add_node_end(head, data);
}

/**
 * pall - prints all elements of the stack/queue.
 * @head: a pointer to the head of the stack/queue.
 * @line_number: is the current line number being executed.
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	(void) line_number;

	if (*head == NULL || line_number == 0)
		return;

	current = *head;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the head of the stack/queue.
 * @head: a pointer to the head of the stack/queue.
 * @line_num: is the current line number being executed.
 */
void pint(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * pop - removes the head element of the stack/queue.
 * @head: a pointer to the head of the stack/queue.
 * @line_num: is the current line number being executed.
 */
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;

	free(temp);
}

/**
 * free_stack - Frees a stack/queue of nodes.
 * @head: A pointer to the head of the stack/queue.
 */
void free_stack(stack_t **head)
{
	stack_t *current, *temp;

	current = *head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

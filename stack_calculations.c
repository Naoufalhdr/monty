#include "monty.h"

/**
 * add - Adds the top two elements of the stack/queue.
 * @head: A pointer to the head of the stack/queue.
 * @l_num: The current line number being executed.
 */
void add(stack_t **head, unsigned int l_num)
{
	stack_t *last, *seconde_last;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}

	last = *head;
	seconde_last = last->next;

	seconde_last->n += last->n;

	*head = seconde_last;
	seconde_last->prev = NULL;
	free(last);
}

/**
 * sub -  subtracts the top element of the stack/queue from the second top
 *        element of the stack/queue.
 * @head: A pointer to the head of the stack/queue.
 * @l_num: The current line number being executed.
 */
void sub(stack_t **head, unsigned int l_num)
{
	stack_t *last, *seconde_last;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}

	last = *head;
	seconde_last = last->next;

	seconde_last->n -= last->n;

	*head = seconde_last;
	seconde_last->prev = NULL;
	free(last);
}

/**
 * divide - divides the second top element of the stack/queue by the top
 *          element of the stack/queue.
 * @head: A pointer to the head of the stack/queue.
 * @l_num: The current line number being executed.
 */
void divide(stack_t **head, unsigned int l_num)
{
	stack_t *last, *seconde_last;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", l_num);
		exit(EXIT_FAILURE);
	}

	last = *head;
	seconde_last = last->next;

	seconde_last->n /= last->n;

	*head = seconde_last;
	seconde_last->prev = NULL;
	free(last);
}

/**
 * mul - multiplies the second top element of the stack/queue with the top
 *       element of the stack/queue.
 * @head: A pointer to the head of the stack/queue.
 * @l_num: The current line number being executed.
 */
void mul(stack_t **head, unsigned int l_num)
{
	stack_t *last, *seconde_last;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}

	last = *head;
	seconde_last = last->next;

	seconde_last->n *= last->n;

	*head = seconde_last;
	seconde_last->prev = NULL;
	free(last);
}

/**
 * mod - computes the rest of the division of the second top element of the
 *       stack/queue by the top element of the stack/queue.
 * @head: A pointer to the head of the stack/queue.
 * @l_num: The current line number being executed.
 */
void mod(stack_t **head, unsigned int l_num)
{
	stack_t *last, *seconde_last;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", l_num);
		exit(EXIT_FAILURE);
	}

	last = *head;
	seconde_last = last->next;

	seconde_last->n %= last->n;

	*head = seconde_last;
	seconde_last->prev = NULL;
	free(last);
}

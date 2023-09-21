#include "monty.h"

/**
 * swap - swaps the top two elements of the stack/queue.
 * @head: A pointer to the head of the stack/queue.
 * @l_num: The current line number being executed.
 */
void swap(stack_t **head, unsigned int l_num)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L<%u>: can't swap, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}

/**
 * pstr - prints the string starting at the head of the stack/queue.
 * @head: A pointer to the head of the stack/queue.
 * @l_num: The current line number being executed.
 */
void pstr(stack_t **head, unsigned int l_num)
{
	stack_t *temp;
	(void) l_num;

	/* If the list is empty, print only a new line */
	if (*head == NULL)
	{
		printf("\n");
		return;
	}

	temp = *head;
	while (temp && temp->n != 0 && (temp->n > 0 && temp->n < 127))
	{
		printf("%c", (char)temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack/queue to the first element.
 * @head: A pointer to the head of the stack/queue.
 * @l_num: The current line number being executed.
 */
void rotl(stack_t **head, unsigned int l_num)
{
	stack_t *first, *second, *current;
	(void) l_num;

	/* Nothing to rotate if the list is empty or has only one element */
	if (*head == NULL || (*head)->next == NULL)
		return;

	first = *head;
	second = first->next;

	/* Update pointers to rotate the list */
	first->next = NULL;
	second->prev = NULL;

	/* Find the new last element & attach it to the current first element*/
	current = second;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->prev = current;

	/* Update the head to point to the new first element */
	*head = second;
}

/**
 * rotr - rotates the stack/queue to the last element.
 * @head: A pointer to the head of the stack/queue.
 * @l_num: The current line number being executed.
 */
void rotr(stack_t **head, unsigned int l_num)
{
	stack_t *current;
	(void) l_num;

	/* Nothing to rotate if the list is empty or has only one element */
	if (*head == NULL || (*head)->next == NULL)
		return;

	current = *head;

	/* Traverse to find the current last element */
	while (current->next != NULL)
		current = current->next;

	/* Update pointers to rotate the list */
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = *head;
	(*head)->prev = current;

	/* Update the head to point to the new first element */
	*head = current;
}

/**
 * pchar - prints the char at the head of the stack/queue.
 * @head: A pointer to the head of the stack/queue.
 * @l: The current line number being executed.
 */
void pchar(stack_t **head, unsigned int l)
{
	int ascii_value;

	if (*head == NULL)
	{
		fprintf(stderr, "L<%u>: can't pchar, stack empty\n", l);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*head)->n;

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L<%u>: can't pchar, value out of range\n", l);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)ascii_value);
}

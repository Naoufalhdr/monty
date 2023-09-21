#include "monty.h"

/**
 * add_node_begin - adds a new node at the beginning of a doubly linked list.
 * @head: a pointer to a pointer to the head of the doubly linked list.
 * @data: The integer value to be stored in the new node.
 */
void add_node_begin(stack_t **head, int data)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 * add_node_end - adds a new node at the end of a doubly linked list.
 * @head: a pointer to a pointer to the head of the doubly linked list.
 * @data: the integer value to be stored in the new node.
 */
void add_node_end(stack_t **head, int data)
{
	stack_t *new_node, *current;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = NULL;

	/* If the list is empty, set the new node as the head */
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* Extern variable, Mode switching (e.g, "stack" and "queue") */
extern char *mode;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Stack operations functions */
void push(stack_t **head, unsigned int line_number, int data);
void pall(stack_t **head, unsigned int line_number);
void free_stack(stack_t **head);
void pint(stack_t **head, unsigned int line_num);
void pop(stack_t **head, unsigned int line_num);

/* Stack calculations functions */
void add(stack_t **head, unsigned int l_num);
void sub(stack_t **head, unsigned int l_num);
void divide(stack_t **head, unsigned int l_num);
void mul(stack_t **head, unsigned int l_num);
void mod(stack_t **head, unsigned int l_num);

/* Stack manipulations functions */
void swap(stack_t **head, unsigned int l_num);
void pchar(stack_t **head, unsigned int l);
void pstr(stack_t **head, unsigned int l_num);
void rotl(stack_t **head, unsigned int l_num);
void rotr(stack_t **head, unsigned int l_num);

/* Linked lists operations */
void add_node_begin(stack_t **head, int data);
void add_node_end(stack_t **head, int data);


/* Execute */
void execute_opcode(char *opcode, char *data, stack_t **head, unsigned int l);

/* helpers */
int _isdigit(char *str);
void _stack(stack_t **head, unsigned int line_number);
void _queue(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int l_num);


#endif /* MONTY_H */

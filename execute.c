#include "monty.h"

/**
 * execute_opcode - executes an opcode operation.
 * @opcode: The name of the opcode to be executed.
 * @data: The argument associated with the opcode (if applicable).
 * @top: a pointer to a pointer to the stack data structure.
 * @l: the line number corresponding to the opcode in the program.
 *
 * Return: 1 if success, otherwise 0.
 */
int execute_opcode(char *opcode, char *data, stack_t **top, unsigned int l)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop},
		{"add", add}, {"nop", nop}, {"swap", swap},
		{"sub", sub}, {"div", divide}, {"mul", mul},
		{"mod", mod}, {NULL, NULL}
	};

	/* Check if the opcode is push command */
	if (strncmp(opcode, "push", strlen("push")) == 0)
	{
		/* Validate that 'data' is provided and is a valid integer */
		if (data == NULL || strlen(data) == 0 || !_isdigit(data))
		{
			fprintf(stderr, "L%u: usage: push integer\n", l);
			return (0);
		}
		push(top, l, atoi(data));
		return (1);
	}

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			/* For opcodes that don't require an argument */
			opcodes[i].f(top, l);
			if (flag)
				return (0);
			return (1);
		}
		i++;
	}

	/* Handle error: Opcode not found */
	fprintf(stderr, "Error: Unknown opcode %s at line %u\n", opcode, l);
	return (0);
}

#include "monty.h"

/* Default mode: "stack" */
char *mode = "stack";

/**
 * main - main function to run monty
 * @argc: number of arguments
 * @argv: list of arguments as strings
 *
 * Return: 0 if success.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *opcode, *data;
	size_t line_size = 0, line_number = 0;
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the monty file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read each line from the monty file */
	while (getline(&line, &line_size, file) != -1)
	{
		line_number++;
		/* Tokenize the line to separate opcode and argument */
		opcode = strtok(line, " \t\n");
		data = strtok(NULL, " \t\n");

		if (!opcode || opcode[0] == '#')
			continue; /* Empty line */
		execute_opcode(opcode, data, &top, line_number);
	}

	/* Close the monty file */
	fclose(file);

	free(line);
	free_stack(&top);

	return (EXIT_SUCCESS);
}

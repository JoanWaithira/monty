#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of pointers to the command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	process_file(file, &stack, line_number);

	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}

/**
 * process_file - Process each line of the input file
 * @file: Pointer to the input file
 * @stack: Pointer to the stack
 * @line_number: Current line number
 */
void process_file(FILE *file, stack_t **stack, unsigned int line_number)
{
	char line[100], *newline, *value_str;

	while (fgets(line, sizeof(line), file))
	{
		newline = strchr(line, '\n');
		if (newline)
			*newline = '\0';

		value_str = strtok(line, " ");
		if (value_str)
		{
			if (strcmp(value_str, "push") == 0)
			{
				value_str = strtok(NULL, " ");
				if (value_str)
				{
					process_push(file, &value_str, stack, line_number);
				}
				else
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					fclose(file);
					free_stack(stack);
					exit(EXIT_FAILURE);
				}
			}
			else if (strcmp(value_str, "pall") == 0)
			{
				process_pall(stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, value_str);
				fclose(file);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
}

/**
 * process_push - Process the push instruction
 * @file: Pointer to the file being read
 * @value_str: String containing the value argument
 * @stack: Pointer to the stack
 * @line_number: Current line number
 */
void process_push(FILE *file, char **value_str, stack_t **stack,
unsigned int line_number)
{
	long value;
	char *endptr;

	if (!*value_str || **value_str == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	value = (int)strtol(*value_str, &endptr, 10);
	if (*endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	push(stack, line_number, value);
}
/**
 * process_pall - Process the pall instruction
 * @stack: Pointer to the stack
 * @line_number: Current line number
 */
void process_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	pall(stack, line_number);
}

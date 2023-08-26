#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(void)
{
	FILE *file = fopen("bytecodes/00.m", "r");
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (!file)
	{
		perror("Error opening file");
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
				process_push(&value_str, stack, line_number);
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
 * @value_str: String containing the value argument
 * @stack: Pointer to the stack
 * @line_number: Current line number
 */
void process_push(char **value_str, stack_t **stack, unsigned int line_number)
{
	long value;
	char *endptr;

	*value_str = strtok(NULL, " ");
	if (*value_str)
	{
		value = strtol(*value_str, &endptr, 10);
		if (*endptr == '\0')
		{
			push(stack, line_number, (int)value);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
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

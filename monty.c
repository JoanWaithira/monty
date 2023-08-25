#include "monty.h"
/**
 * main - Entry point of the Monty interpreter
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(void)
{
	char opcode[10], line [100];
	int value;
	FILE *file = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	file = fopen("bytecodes/00.m", "r");
	if (!file)
	{
		perror("Error opening file");
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		char *value_str;
		char *newline = strchr(line, '\n');

		if (newline)
		{
			*newline = '\0';
		}
		value_str = strtok(line, " \t\r");
		if (value_str)
		{
			if (strcmp(value_str, "push") == 0)
			{
				value_str = strtok(NULL, " \t\r");
				if (value_str && sscanf(value_str, "%d", &value) == 1)
				{
					push(&stack, line_number, value);
				}
				else
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					fclose(file);
					free_stack(&stack);
					return (EXIT_FAILURE);
				}
			}
			else if (strcmp(value_str, "pall") == 0)
			{
				pall(&stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				free_stack(&stack);
				return (EXIT_FAILURE);
			}
		}
		line_number++;
	}
	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}

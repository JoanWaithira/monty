#include "monty.h"
/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	char opcode[10];
	int value;
	FILE *file;
	stack_t *stack;

	file = fopen(argv[1], "r");
	stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	if (!file)
	{
		perror("Error opening file");
		return (EXIT_FAILURE);
	}

	while (fscanf(file, "%s", opcode) != EOF)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				fprintf(stderr, "Error: Usage: push <int>\n");
				fclose(file);
				return (EXIT_FAILURE);
			}
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
	}
	fclose(file);
	return (EXIT_SUCCESS);
}

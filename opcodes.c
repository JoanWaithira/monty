#include "monty.h"

/**
 * push - Implementation of the push opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 * @value: Value to push onto the stack
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \n");
	int value;
	stack_t *new_node;
	*stack = NULL;

	if (!value_str)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}


	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
/**
 * pall - Implementation of the pall opcode
 * @line_number: Pointer to the stack
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	*stack = NULL;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

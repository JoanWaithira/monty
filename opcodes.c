#include "monty.h"

/**
 * push - Implementation of the push opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 * @value: Value to push onto the stack
 */

void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	(void)line_number;

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
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

#include "monty.h"

/**
 * op_pop - Implementation of the pop opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

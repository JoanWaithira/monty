#include "monty.h"

/**
 * op_add - Implementation of the add opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	op_pop(stack, line_number);
}

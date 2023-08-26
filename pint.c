#include "monty.h"

/**
 * op_pint - Implementation of the pint opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

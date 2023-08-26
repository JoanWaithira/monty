#include "monty.h"
/**
 * free_stack - A function that frees the stack.
 * @stack: Stack in question
 * stack: Stack in question
 * Return: Memory freed
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}


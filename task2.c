#include "monty.h"

/**
 * pop - remove the top element of the stack
 * @stack: linked list
 * @line_number: thenumber of line the error happened
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(ptr);
}

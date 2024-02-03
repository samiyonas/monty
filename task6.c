#include "monty.h"

/**
 * sub - subtract the first two elemnts of the stack
 * @stack: linked list
 * @line_number: number of line
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;

	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	*stack = (*stack)->next;

	free(ptr);
}

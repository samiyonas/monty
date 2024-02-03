#include "monty.h"

/**
 * _mul - multiple the first two elements
 * @stack: linked list
 * @line_number: number of lines
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;

	result = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = result;
	*stack = (*stack)->next;

	free(ptr);
}

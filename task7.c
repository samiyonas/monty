#include "monty.h"

/**
 * _div - divides the second element by the first element
 * @stack: linked list
 * @line_number: number of lines
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;

	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	*stack = (*stack)->next;

	free(ptr);
}

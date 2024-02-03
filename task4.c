#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: linked list
 * @line_number: number of lines
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;

	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;
	*stack = (*stack)->next;
	free(ptr);
}

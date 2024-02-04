#include "monty.h"

/**
 * pchar - char at the top of the stack
 * @stack: linked list
 * @line_number: number of line
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char a;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	printf("%c\n", a);
}

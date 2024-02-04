#define _GNU_SOURCE
#include "monty.h"

/**
 * pstr - prints string starting at the top of the stack
 * @stack: linked list
 * @line_number: number of line
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	UNUSED(line_number);

	while (ptr != NULL && ptr->n != 0 && isascii(ptr->n))
	{
		putchar(ptr->n);
		ptr = ptr->next;

		if (ptr == *stack)
		{
			break;
		}
	}
	printf("\n");
}

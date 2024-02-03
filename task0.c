#include "monty.h"

/**
 * push - push to the stack
 * @stack: linked list
 * @line_number: number of line
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *str_data;
	int data;

	str_data = strtok(NULL, " \n\t\r");

	if (str_data == NULL || check_for_digit(str_data) == 1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	data = atoi(str_data);
	add_node(stack, data);
}
/**
 * pall - print all the values of the stack
 * @stack: linked list
 * @line_number: number of line
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	UNUSED(line_number);

	if (*stack == NULL)
	{
		return;
	}

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
		if (ptr == *stack)
		{
			return;
		}
	}
}

#include "monty.h"

/**
 * validity_check - check for validity
 * @head: a linked list
 * @op: string
 * @Line: unsigned int
 *
 * Return: void
 */
void validity_check(stack_t **head, char *op, unsigned int Line)
{
	int i;
	instruction_t a[] = {{"push", push}, {NULL, NULL}};

	for (i = 0; a[i].opcode != NULL; i++)
	{
		if (strcmp(a[i].opcode, op) == 0)
		{
			a[i].f(head, Line);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", Line, op);
	exit(EXIT_FAILURE);
}
/**
 * add_node - add node at the beginning
 * @head: linked list
 * @n: integer
 *
 * Return: void
 */
void add_node(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	if (*head == NULL)
	{
		*head = new;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		return;
	}
	new->next = *head;
	(*head)->prev = new;
	new->prev = NULL;
	*head = new;
}
/**
 * check_for_digit - check if it is a digit
 * @num: string
 *
 * Return: int
 */
int check_for_digit(char *num)
{
	int i;

	if (num == NULL)
	{
		return (1);
	}
	for (i = 0; num[i] != '\0'; i++)
	{
		if (i == 0 && num[i] == '-')
		{
			continue;
		}
		if (!isdigit(num[i]))
		{
			return (1);
		}
	}
	return (0);
}

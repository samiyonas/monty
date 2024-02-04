#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: int
 */
int main(int argc, char **argv)
{
	unsigned int line_n = 0;
	stack_t *stack = NULL;
	FILE *file;
	ssize_t read;
	size_t len = 0;
	char *line = NULL, *operator;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_n++;
		operator = strtok(line, "\n\t\r ");
		if (operator != NULL && operator[0] != '#')
		{
			validity_check(&stack, operator, line_n);
		}
	}
	fclose(file);
	exit(EXIT_SUCCESS);
}

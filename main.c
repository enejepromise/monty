#define _GNU_SOURCE
#include "monty.h"

/* Define Global variable */
glb_var *glbs = NULL;

/**
 * main - an interpreter for Monty ByteCodes files
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 on success, 1 otherwise
 */
int main(int argc, char *argv[])
{
	/* Initialize variables */
	char *line = NULL;
	size_t len = 0, line_num = 1;
	stack_t *stack = NULL;

	/* Initialize global variables */
	initialize_globals();

	/* Check for correct cmdline input */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_glbs(1);
	}
	glbs->file = fopen(argv[1], "r");

	/* check for variable file input */
	if (glbs->file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_glbs(1);
	}

	/* Read file line by line */
	while (getline(&line, &len, glbs->file) != -1)
	{
		glbs->blck = line;
		execute(&stack, line_num);
		++line_num;
	}
	/* Handle memory and exit successfully */
	free_stack(stack);
	free_glbs(0);
	return (0);
}

/**
 * initialize_globals - initialize global varibles
 *
 * Return: void
 */
void initialize_globals(void)
{
	glbs = malloc(sizeof(glb_var));

	if (glbs == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	glbs->blck = NULL;
	glbs->file = NULL;
	glbs->args = NULL;
	glbs->opcd = NULL;
}

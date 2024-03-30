#include <string.h>
#include "monty.h"

/**
 * execute - runs the opcodes from <file>
 * @stack: stack to run codes on
 * @line_num: current line number
 *
 * Return: void
 */

void execute(stack_t **stack, unsigned int line_num)
{
	/* Define variables and instructions */
	unsigned int i = 0;
	instruction_t instructions[] = {
		{"add", f_add},
		{"pop", f_pop},
		{"swap", f_swap},
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{NULL, NULL}
	};

	/* Retrieve opcode and its args */
	glbs->opcd = strtok(glbs->blck, " \n\t");
	glbs->args = strtok(NULL, " \n\t");

	/* Check if opcode is valid */
	while (instructions[i].opcode != NULL && glbs->opcd != NULL)
	{
		if (strcmp(glbs->opcd, instructions[i].opcode) == 0)
		{
			/* Execute opcode */
			instructions[i].f(stack, line_num);
			return;
		}
		++i;
	}

	/* If invalid, print error message */
	if (glbs->opcd != NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, glbs->opcd);
		free_stack(*stack);
		free_glbs(1);
	}
}

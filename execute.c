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
		{"add", f_add}, {"div", f_div},
		{"mod", f_mod}, {"mul", f_mul},
		{"nop", f_nop}, {"sub", f_sub},
		{"pop", f_pop}, {"swap", f_swap},
		{"pall", f_pall}, {"pint", f_pint},
		{"pstr", f_pstr}, {"push", f_push},
		{"pchar", f_pchar}, {NULL, NULL}
	};

	/* Retrieve opcode and its args */
	glbs->opcd = strtok(glbs->blck, " \n\t");
	glbs->args = strtok(NULL, " \n\t");

	/* Check if opcode is valid */
	while (instructions[i].opcode != NULL && glbs->opcd != NULL)
	{
		/* Ignore comments */
		if (glbs->opcd[0] == '#')
			return;

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

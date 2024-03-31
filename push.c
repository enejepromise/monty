#include "monty.h"

/**
 * f_push - implements a stack's push function
 * @stack: stack to be implemented on
 * @line_num: current line number
 *
 * Return: void
 */
void f_push(stack_t **stack, unsigned int line_num)
{
	/* Create new element */
	unsigned int i, flag = 0;
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		free_glbs(1);
	}
	/* Check if argument is valid */
	if (glbs->args == NULL)
		flag = 1;

	else
	{
		for (i = 0; glbs->args[i] != '\0'; ++i)
		{
			if (glbs->args[i] < '0' || glbs->args[i] > '9')
				flag = 1;
		}
	}
	/* Handle invalid arguments */
	if (flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free(new);
		free_stack(*stack);
		free_glbs(1);
	}
	/* push and link new element unto the stack */
	new->n = atoi(glbs->args);
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

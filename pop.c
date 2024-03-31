#include "monty.h"

/**
 * f_pop - removes the top element of the stack
 * @stack: stack to be implemented in
 * @line_num: current line number
 *
 * Return: void
 */
void f_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_glbs(1);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

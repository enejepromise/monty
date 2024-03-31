#include "monty.h"
/**
 * f_pint -  prints the value at the top of the stack
 * @stack: stack to be executed on
 * @line_num: current line number
 * Return: void
 */
void f_pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		free_glbs(1);
	}
	printf("%d\n", (*stack)->n);
}

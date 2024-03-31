#include "monty.h"

/**
 * f_pchar - prints char at stack's top
 * @stack: stack to be implemented on
 * @line_num: current line number
 *
 * Return: void
 */
void f_pchar(stack_t **stack, unsigned int line_num)
{
	stack_t *top = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		free_glbs(1);
	}
	top = *stack;

	if (top->n < 32 || top->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		free_stack(*stack);
		free_glbs(1);
	}
	printf("%c\n", top->n);
}

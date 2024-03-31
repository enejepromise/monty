#include "monty.h"

/**
 * f_div - divides the stack's second top element by the top
 * @stack: stack to be implemented on
 * @line_num: current line number
 *
 * Return: void
 */
void f_div(stack_t **stack, unsigned int line_num)
{
	stack_t *top = NULL, *second = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		free_stack(*stack);
		free_glbs(1);
	}

	top = *stack;
	second = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_stack(*stack);
		free_glbs(1);
	}

	second->n /= top->n;
	f_pop(stack, line_num);
}

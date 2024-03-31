#include "monty.h"

/**
 * f_mul -  multiplies the stack's second top element with the top
 * @stack: stack to be implemented on
 * @line_num: current line number
 *
 * Return: void
 */
void f_mul(stack_t **stack, unsigned int line_num)
{
	stack_t *top = NULL, *second = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free_stack(*stack);
		free_glbs(1);
	}

	top = *stack;
	second = top->next;

	second->n *= top->n;
	f_pop(stack, line_num);
}

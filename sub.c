#include "monty.h"

/**
 * f_sub - subtracts the stack's top element from the second
 * @stack: stack to be implemented on
 * @line_num: current line number
 *
 * Return: void
 */
void f_sub(stack_t **stack, unsigned int line_num)
{
	stack_t *top = NULL, *second = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		free_stack(*stack);
		free_glbs(1);
	}

	top = *stack;
	second = top->next;

	second->n -= top->n;
	f_pop(stack, line_num);
}

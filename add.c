#include "monty.h"

/**
 * f_add - adds the stack's top two elements
 * @stack: stack to be implemented on
 * @line_num: current line number
 *
 * Return: void
 */
void f_add(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_stack(*stack);
		free_glbs(1);
	}

	top = *stack;
	second = top->next;

	second->n += top->n;
	f_pop(stack, line_num);
}

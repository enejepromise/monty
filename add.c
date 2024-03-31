#include "monty.h"

/**
 * f_add - adds the top two elements of the stack
 * @stack: stack to be implemented in
 * @line_num: current line number
 *
 * Return: void
 */
void f_add(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *second;

	/* verify stack lenght */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_stack(*stack);
		free_glbs(1);
	}
	top = *stack;
	second = top->next;

	/* Add the top to second */
	second->n += top->n;

	/* Pop top */
	f_pop(stack, line_num);
}

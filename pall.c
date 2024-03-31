#include "monty.h"
/**
 * f_pall - prints all elements of a stack
 * @stack: stack to be printed
 * @line_num: current line number
 * Return: void
 */
void f_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *cur = *stack;
	/* Indicate line_num as unused */
	(void)line_num;
	/* Prints each element */
	while (cur != NULL)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}

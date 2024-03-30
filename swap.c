#include "monty.h"

/**
 * f_swap -  swaps the top two elements of the stack
 * @stack: stack to be implemented in
 * @line_num: current line number
 *
 * Return: void
 */
void f_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *cur = NULL, *next_node = NULL;

	/* Verify Stack Length */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		free_stack(*stack);
		free_glbs(1);
	}

	cur = *stack;
	next_node = (*stack)->next;

	/* Perform Swap */
	cur->next = next_node->next;
	next_node->next = cur;
	next_node->prev = cur->prev;
	cur->prev = next_node;

	/* Link Adjacent Nodes if it exists*/
	if (cur->next != NULL)
		cur->next->prev = cur;

	/* Update Stack Pointer */
	*stack = next_node;
}

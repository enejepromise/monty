#include "monty.h"
/**
 * free_stack - frees a doubly linked stack
 * @stack: stack to be freed
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *head = stack;

	/* frees each stack node */
	while (head != NULL)
	{
		stack = head->next;
		free(head);
		head = stack;
	}
}

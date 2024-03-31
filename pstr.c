#include "monty.h"

/**
 * f_pstr - prints the string starting at the stack's top
 * @stack: stack to be implemented on
 * @line_num: current line number
 *
 * Return: void
 */
void f_pstr(stack_t **stack, unsigned int line_num)
{
	unsigned int i = 0;
	stack_t *cur = *stack;
	char *str = (char *)malloc(sizeof(char) + line_num);

	if (str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		free_glbs(1);
	}

	while (cur != NULL && cur->n != 0)
	{
		if (cur->n < 32 || cur->n > 126)
			break;

		str[i++] = cur->n;
		cur = cur->next;
	}
	str[i] = '\0';

	printf("%s\n", str);
	free(str);
}

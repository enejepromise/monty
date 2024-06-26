#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct glb_var - all global variables
 * @blck: pointer to getline line input
 * @args: pointer to instruction arguments
 * @opcd: pointer to opcode
 * @file: pointer to file
 *
 * Description: all global variables
 */
typedef struct glb_var
{
	char *blck;
	char *args;
	char *opcd;
	FILE *file;
} glb_var;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern glb_var *glbs;

void free_glbs(int flag);
void initialize_globals(void);
void free_stack(stack_t *stack);
void f_add(stack_t **stack, unsigned int line_num);
void f_div(stack_t **stack, unsigned int line_num);
void f_mod(stack_t **stack, unsigned int line_num);
void f_mul(stack_t **stack, unsigned int line_num);
void f_nop(stack_t **stack, unsigned int line_num);
void f_sub(stack_t **stack, unsigned int line_num);
void f_pop(stack_t **stack, unsigned int line_num);
void f_pall(stack_t **stack, unsigned int line_num);
void f_pint(stack_t **stack, unsigned int line_num);
void f_pstr(stack_t **stack, unsigned int line_num);
void f_push(stack_t **stack, unsigned int line_num);
void f_swap(stack_t **stack, unsigned int line_num);
void f_pchar(stack_t **stack, unsigned int line_num);
void execute(stack_t **stack, unsigned int line_num);

#endif /*MONTY_H*/

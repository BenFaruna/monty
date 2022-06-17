#ifndef MONTY_H
#define MONTY_H

#define SEPARATORS " \t\n\r"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 *
 * @opcode: the opcode
 * @f: funcion to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t **global_free;

void interpreter(char *function, stack_t **node, unsigned int line_num);
stack_t *add_node(stack_t **head, const int num); 
size_t print_stack(stack_t *head);

void push(stack_t **node, unsigned int line_num);
void pall(stack_t **node, unsigned int line_num);
void pint(stack_t **node, unsigned int line_num);
void pop(stack_t **node, unsigned int line_num);
void swap(stack_t **node, unsigned int line_num);
void add(stack_t **node, unsigned int line_num);
void nop(stack_t **node, unsigned int line_num);
void sub(stack_t **node, unsigned int line_num);
void _div(stack_t **node, unsigned int line_num);
void _mul(stack_t **node, unsigned int line_num);
void _mod(stack_t **node, unsigned int line_num);
void pchar(stack_t **node, unsigned int line_num);
void pstr(stack_t **node, unsigned int line_num);
void rotl(stack_t **node, unsigned int line_num);
void rotr(stack_t **node, unsigned int line_num);

void free_stack(stack_t *head);
void free_all();
#endif /* MONTY_H */

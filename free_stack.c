#include "monty.h"

/**
 * free_stack - this function frees up memory used by a stack;
 *
 * @head: pointer to top of stack
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * free_all - function for free
 */
void free_all(void)
{
	stack_t *node_free;
	stack_t *temp = NULL;

	node_free = *global_free;

	while (node_free)
	{
		temp = node_free->next;
		free(node_free);
		node_free = temp;
	}
}

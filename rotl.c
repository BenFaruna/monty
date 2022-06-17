#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @node: double pointer to the begining of the list
 * @line_num: script line number
 */
void rotl(stack_t **node, unsigned int line_num)
{
	stack_t *temp, *top;
	(void) line_num;

	if (!node || !(*node) || !(*node)->next)
		return;
	temp = *node;
	top = temp->next;
	top->prev = NULL;

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *node;

	(*node)->next = NULL;
	(*node)->prev = temp;

	*node = top;
}

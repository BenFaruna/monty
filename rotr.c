#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @node: double pointer to the begining of the list
 * @line_num: script line number
 */

void rotr(stack_t **node, unsigned int line_num)
{
	stack_t *temp;
	(void) line_num;

	if (!node || !(*node) || !(*node)->next)
		return;

	temp = *node;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *node;
	temp->prev->next = NULL;
	temp->prev = NULL;

	(*node)->prev = temp;
	(*node) = temp;
}

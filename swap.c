#include "monty.h"

/**
 * swap - swap the top two elements of the stack
 *
 * @node: pointer to stack
 * @line_num: current line number
 */
void swap(stack_t **node, unsigned int line_num)
{
	stack_t *temp;

	if ((!*node || !node) || !(*node)->next)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *node;
	*node = (*node)->next;
	temp->next = (*node)->next;
	(*node)->next = temp;
	temp->prev = *node;
}

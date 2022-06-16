#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @node: pointer to stack
 * @line_num: current line number
 */
void add(stack_t **node, unsigned int line_num)
{
	stack_t *temp;

	if ((!*node || !node) || !(*node)->next)
	{
		dprintf(2, "L%u: can't add, stack too short", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp = *node;
	temp->next->n = temp->next->n + temp->n;
	*node = temp->next;
	(*node)->prev = NULL;
	free(temp);
}

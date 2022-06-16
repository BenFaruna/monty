#include "monty.h"

/**
 * pop - removes the top node of a stack
 *
 * @node: pointer to stack
 * @line_num: current line number
 */
void pop(stack_t **node, unsigned int line_num)
{
	stack_t *temp = NULL;

	if (!*node || !node)
	{
		dprintf(2, "L%u: can't pop an empty stack", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *node;
	*node = temp->next;
	free(temp);
}

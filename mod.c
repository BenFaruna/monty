#include "monty.h"

/**
 * _mod - computes the rest division of second top element by top element
 *
 * @node: pointer to top of stack
 * @line_num: current line number
 */
void _mod(stack_t **node, unsigned int line_num)
{
	stack_t *temp;

	if ((!*node || !node) || !(*node)->next)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*node)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *node;
	temp->next->n = temp->next->n % temp->n;
	temp->next->prev = NULL;
	*node = temp->next;
	free(temp);
}

#include "monty.h"

/**
 *  sub - substract the top element of the stack from the second top element
 *
 * @node: pointer to top of stack
 * @line_num: current line number
 */
void sub(stack_t **node, unsigned int line_num)
{
	stack_t *temp;

	if ((!*node || !node) || !(*node)->next)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *node;
	temp->next->n = temp->next->n - temp->n;
	temp->next->prev = NULL;
	*node = temp->next;
	free(temp);
}

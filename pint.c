#include "monty.h"

/**
 * pint - prints the top element in a stack
 *
 * @node: pointer to stack
 * @line_num: current line number
 */
void pint(stack_t **node, unsigned int line_num)
{
	if (!*node || !node)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*node)->n);
}

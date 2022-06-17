#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 *
 * @node: pointer to top of the node
 * @line_num: current line number
 */
void pchar(stack_t **node, unsigned int line_num)
{
	int num = 0;

	if (!*node || !node)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	num = (*node)->n;
	if ((num < 33) || (num > 127))
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	putchar(num);
	putchar('\n');
}

#include "monty.h"

/**
 * pstr - prints the string  starting at the top of the stack
 *
 * @node: pointer to top of stack
 * @line_num: current line number
 */
void pstr(stack_t **node, unsigned int __attribute__((unused)) line_num)
{
	stack_t *temp = *node;

	while (temp && (temp->n != 0) && ((temp->n) > 32 && ((temp->n) < 128)))
	{
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}

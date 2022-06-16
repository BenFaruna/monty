#include "monty.h"

/**
 * pall - print the stack
 *
 * @head: pointer to head of linked list
 * @line_num: current line number
 */
void pall(stack_t **head, unsigned int __attribute__((unused)) line_num)
{
	stack_t *temp = *head;

	if (*head && head)
	{
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}

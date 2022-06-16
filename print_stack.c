#include "monty.h"

/**
 * print_stack - print the elements in a stack
 *
 * @head: pointer to the first element in the stack
 *
 * Return: number of elements in the stack
 */
size_t print_stack(stack_t *head)
{
	size_t count = 0;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		count++;
	}
	return (count);
}

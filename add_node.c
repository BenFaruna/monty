#include "monty.h"

/**
 * add_node - adds node to the top of the stack
 *
 * @head: pointer to the head of the stack
 * @num: integer value of the node
 *
 * Return: pointer to the new node
 */
stack_t *add_node(stack_t **head, const int num)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = num;
	new_node->prev = NULL;
	temp = *head;
	if (*head == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = temp;
		temp->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}


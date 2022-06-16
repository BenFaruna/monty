#include "monty.h"

/**
 * check_digit - check if string is a number
 * @param: param to push
 * @line_num: current line number
 *
 * Return: value of param
 */
int check_digit(char *param, unsigned int line_num)
{
	int num;

	num = atoi(param);
	if (num == 0 && strcmp(param, "0") != 0)
	{
		dprintf(2, "L%u: usage: push integer\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	return (num);
}

/**
 * push - it adds element to the top of the stack
 *
 * @node: pointer to head of stack
 * @line_num: current line number
 */
void push(stack_t **node, unsigned int line_num)
{
	int num;
	char *param;

	param = strtok(NULL, SEPARATORS);

	if (!param)
	{
		dprintf(2, "L%u: usage: push integer\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	num = check_digit(param, line_num);
	if (!add_node(node, num))
	{
		dprintf(2, "Error: malloc failed\n");
		free_all();
		exit(EXIT_SUCCESS);
	}
}

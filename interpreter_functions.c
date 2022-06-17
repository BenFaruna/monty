#include "monty.h"

/**
 * interpreter - search for monty function to be used
 * @function: function to be searched for
 * @node: pointer to head of stack
 * @line_num: current line number
 */
void interpreter(char *function, stack_t **node, unsigned int line_num)
{
	size_t i;

	instruction_t commands[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	for (i = 0; commands[i].opcode; i++)
	{
		if (strcmp(commands[i].opcode, function) == 0)
		{
			commands[i].f(node, line_num);
			return;
		}
	}
	dprintf(2, "L%u: unknown instruction %s\n", line_num, function);
	free_all();
	exit(EXIT_FAILURE);
}

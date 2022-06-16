#include "monty.h"

stack_t **global_free;

/**
 * main - controls the behaviour of the monty interpreter
 *
 * @argc: argument count
 * @argv: array of arguments (strings)
 *
 * Return: EXIT_SUCCESS on successful run and EXIT_FAILURE otherwise
 */
int main(int argc, char **argv)
{
	FILE *monty_file;
	unsigned int line_num = 0;
	char *dataptr = NULL, *function = NULL;
	size_t size = 0;
	stack_t *node = NULL;

	global_free = &node;
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		free_all();
		exit(EXIT_FAILURE);
	}
	while (getline(&dataptr, &size, monty_file) != -1)
	{
		line_num++;
		function = strtok(dataptr, SEPARATORS);
		if (function != NULL && function[0] != '#')
			interpreter(function, &node, line_num);
	}
	pclose(monty_file);
	if (dataptr)
		free(dataptr);
	free_all();

	exit(EXIT_SUCCESS);
}

#include "simple_shell.h"

/**
 *main - Entry point for the simple shell.
 *
 *Return: Always 0.
 */

int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		display_prompt();
		line = read_line();
		args = split_line(line);
		status = execute(args);
		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}

#include "simple_shell.h"


/**
* display_prompt - Displays the shell prompt.
**/

void display_prompt(void)
{
        write(STDOUT_FILENO, "$", 2);
}


/**
 *main - Entry point for the simple shell.
 *
 *Return: Always 0.
 */
int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		display_prompt();
		line = read_line();
		args = split_line(line);
		execute(args);

		free(line);
		free(args);
	}

	return (0);
}

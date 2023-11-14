#include "shell.h"


/**
 * main - Entry point for the simple shell program.
 *
 * Description:
 * The main function sets up a shell interface, reads and processes user input
 * in a loop, and executes commands until the user decides to exit.
 *
 * Return:
 * Returns 0 on successful execution.
 */
int main(void)
{
char *line;
char **args;
int status;

signal(SIGINT, handle_signal);

do {
printf("#cisfun$ ");
line = read_line();
args = split_line(line);
status = execute_command(args);

free(line);
free(args);
} while (status);

return (0);
}


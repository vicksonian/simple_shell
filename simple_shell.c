#include "simple_shell.h"

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
size_t len = 0;
ssize_t read;
while (1)
{
printf("#cisfun$ ");
read = getline(&line, &len, stdin);
if (read == -1)
{
if (feof(stdin))
{
printf("\n");
free(line);
exit(EXIT_SUCCESS);
}
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}
line[read - 1] = '\0';
if (strchr(line, ' ') != NULL)
{
fprintf(stderr, "./shell: Command lines should only be one word.\n");
}
else
{
if (execute_command(line) == -1)
{
fprintf(stderr, "./shell: Command not found\n");
}
}

free(line);
line = NULL;
}

return (0);
}

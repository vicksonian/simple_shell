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
/* Remove the newline character*/
line[read - 1] = '\0';

if (execute_command(line) == -1)
{
fprintf(stderr, "./shell: No such file or directory\n");
}

free(line);
line = NULL;
}

return (0);
}


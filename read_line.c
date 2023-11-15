#include "simple_shell.h"

/**
 * display_prompt - Displays the shell prompt.
 *
 * Description:
 * This function prints the shell prompt ("#cisfun$ ") to the standard output.
 */
void display_prompt(void)
{
printf("#cisfun$ ");
}

/**
 * read_line - Reads a line of input from the user.
 *
 * Return:
 * Returns a dynamically allocated string containing the user's input line.
 * If an error occurs, the program exits with an appropriate error message.
 */
char *read_line(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;

display_prompt();

read = getline(&line, &len, stdin);

if (read == -1)
{
if (feof(stdin))
{
printf("\n");
exit(EXIT_SUCCESS);
}
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}

return (line);
}


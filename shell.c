#include "shell.h"

/**
 * main - Simple Shell
 *
 * This is the main function for a simple shell. It prompts the user for input,
 * reads the input line, and processes the command by executing the appropriate
 * function.
 *
 * Return: Always 0
 */
int main(void)
{
char *line = NULL;
size_t len = 0;

while (1)
{
printf("#cisfun$ ");
getline(&line, &len, stdin);

/* Process the input line, execute commands, etc. */
/* Add your code for processing the command here */

/* Free the allocated memory for the line */
free(line);
}

return 0;
}


#include "shell.h"

/**
 * read_line - Reads a line of input from the standard input.
 *
 * Return:
 * Returns a dynamically allocated string containing the input line.
 * Exits the program with success if the end of file (EOF) is reached.
 * Exits the program with failure if an error occurs during reading.
 */

char *read_line(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;

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


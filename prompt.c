#include "shell.h"

/**
* Read a line from the standard input.
*
* This function reads a line of input from the standard input (stdin) and
* returns it as a dynamically allocated string. The caller is responsible
* for freeing the memory allocated for the returned string.
*
* @return A dynamically allocated string containing the input line.
*         It is the caller's responsibility to free the memory.
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


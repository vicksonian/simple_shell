#include "simple_shell.h"

/**
 *_getline - Read a line of input from the user.
 *
 *@line: Pointer to the buffer where the line will be stored.
 *@bufsize: Size of the buffer.
 *
 *Return: The number of characters read, or -1 on failure.
 */
ssize_t _getline(char **line, size_t *bufsize)
{
	ssize_t characters_read;

	characters_read = getline(line, bufsize, stdin);

	if (characters_read == -1)
	{
		if (feof(stdin))
		{
			free(*line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("_getline");
			exit(EXIT_FAILURE);
		}
	}

	return (characters_read);
}

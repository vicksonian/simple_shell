#include "shell.h"



/**
 * Reads a line from standard input
 *This function reads input from standard
 *input and dynamically allocates memory
 *for the input line. It adjusts the memory
 *as needed to accommodate the input.
 *
 *@param line_index A pointer to the size_t
 *variable that tracks the index of the line.
 *return: A pointer to the dynamically allocated input line.
 *Returns: NULL on EOF or if no input is provided.
 */
char *_getline(size_t *line_index)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index;
	static size_t bytes_read;

	char *line = NULL;

	while (1)
	{
		if (buffer_index == bytes_read)
		{
			bytes_read = fread(buffer, 1, BUFFER_SIZE, stdin);
			buffer_index = 0;

			if (bytes_read == 0 && *line_index == 0)
			{
				return (NULL);
			}
		}
		if (*line_index % BUFFER_SIZE == 0)
		{
			size_t new_size = (*line_index / BUFFER_SIZE + 1) * BUFFER_SIZE;
			char *new_line = realloc(line, new_size);

			if (new_line == NULL)
			{
				perror("realloc");
				free(line);
				return (NULL);
			}
			line = new_line;
		}
		if (buffer[buffer_index] == '\n')
		{
			line[*line_index] = '\0';
			return (line);
		}

		line[*line_index++] = buffer[buffer_index++];
	}
}

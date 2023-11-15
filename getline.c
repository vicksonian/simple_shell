#include "simple_shell.h"


#define BUFFER_SIZE 1024

/**
* input_buf - Initialize the input buffer.
* @input: Pointer to the InputBuffer structure.
*/

void input_buf(InputBuffer *input)
{
	input->buffer = NULL;
	input->size = 0;
	input->index = 0;
}
/**
* get_input - Get the current content of the input buffer.
* @input: Pointer to the InputBuffer structure.
* Return: Pointer to the input buffer.
*/
char *get_input(InputBuffer *input)
{
	return (input->buffer);
}

/**
* read_buf - Read input from stdin and update the input buffer.
* @input: Pointer to the InputBuffer structure.
* Return: Number of bytes read.
*/

size_t read_buf(InputBuffer *input)
{
	size_t new_size = input->size + BUFFER_SIZE;
	char *new_buffer = realloc(input->buffer, new_size);
	size_t bytes_read;

	if (new_buffer == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}

	bytes_read = fread(input->buffer + input->index, 1, BUFFER_SIZE, stdin);
	input->index += bytes_read;

	return (bytes_read);
}




/**
* _getline - Read a line from the input buffer.
* @input: Pointer to the InputBuffer structure.
* Return: Pointer to the line read.
*/

char *_getline(InputBuffer *input)
{
	size_t i;

	for (i = input->index; i < input->size; i++)
	{
		if (input->buffer[i] == '\n')
		{
			input->buffer[i] = '\0';
			input->index = i + 1;
			return (input->buffer);
		}
	}

	while (read_buf(input) > 0)
	{
		for (; i < input->index; i++)
		{
			if (input->buffer[i] == '\n')
			{
				input->buffer[i] = '\0';
				input->index = i + 1;
				return (input->buffer);
			}
		}
	}

	return (NULL);
}

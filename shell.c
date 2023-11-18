#include "shell.h"


/**
* main - function for the simple shell.
*
* Return: Always returns 0.
*/

int main(void)
{
	char *input;
	size_t line_index = 0;

	while (1)
	{
		printf("$ ");
		input = _getline(&line_index);
		if (input == NULL)
		{
			printf("\n");
			break; /*Exit the loop on EOF (Ctrl+D) */
		}

		if (strcmp(input, "exit") == 0)
		{
			shell_exit();
		}
		else
		{
			execute_command(input);
		}

		free(input);
	}

	return (0);
}

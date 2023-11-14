#include "shell.h"

/**
 * main - Simple shell program
 * Return: 0 on success
 */
int main(void)
{
	char *input;

	while (1)
{
	display_prompt();
	input = read_input();

	if (input == NULL)
		{
		printf("\n");
		break; /* Exit on EOF (Ctrl+D) */
		}

	execute_command(input);

	free(input);
	}

	return (0);
}


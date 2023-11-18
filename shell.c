#include "shell.h"

/**
 *main - Entry point for the simple shell.
 *
 *This function represents the entry point for the simple shell program.
 *It continuously prompts the user for commands, executes them, and
 *terminates when the user enters "exit"
 *or the end of file (Ctrl+D) is reached.
 *
 *Return: Always 0.
 */

#include "shell.h"

int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("($) ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break; /*Exit the loop on EOF (Ctrl+D)*/
		}

		/*Remove newline character from the input*/
		input[strcspn(input, "\n")] = '\0';

		execute_command(input);
	}

	return (0);
}

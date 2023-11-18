#include "shell.h"

/**
 *shell_exit - Exit the shell.
 *
 *This function prints a message indicating that the shell is exiting
 *and then terminates the program with EXIT_SUCCESS.
 */

void shell_exit(void)
{
	printf("Exiting the shell.\n");
	exit(EXIT_SUCCESS);
}

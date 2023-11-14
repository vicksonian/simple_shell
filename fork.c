#include "shell.h"

/**
* handle_signal - Handles the specified signal
* @signal: The signal number
*
* This function is a signal handler that handles
* the specified signal. It simply
* prints a newline, displays the shell prompt,
* and flushes the standard output.
*/
void handle_signal(int signal)
{
	(void)signal;
	putchar('\n');
	printf("# $ ");
	fflush(stdout);
}


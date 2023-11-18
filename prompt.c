#include "shell.h"
#define PROMPT "$ "
/**
 *display_prompt - Displays the shell prompt.
 *Return: returns void.
 */

void display_prompt(void)
{
	puts(PROMPT);
	fflush(stdout);
}

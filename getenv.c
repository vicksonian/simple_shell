#include "shell.h"

/**
 *Set environment variable.
 *@param args List of args. args[0] is "setenv", args[1] is the variable, and args[2] is the value.
 *@return Always returns 1, to continue executing.
 */
int shell_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		perror("shell: expected arguments to \"setenv\"");
	}
	else
	{
		if (setenv(args[1], args[2], 1) != 0)
		{
			perror("shell");
		}
	}

	return (1);
}

/**
 *Unset environment variable.
 *@param args List of args. args[0] is "unsetenv", args[1] is the variable.
 *@return Always returns 1, to continue executing.
 */
int shell_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		perror("shell: expected argument to \"unsetenv\"");
	}
	else
	{
		if (unsetenv(args[1]) != 0)
		{
			perror("shell");
		}
	}

	return (1);
}

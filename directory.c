#include "shell.h"

/**
 *Builtin command: change directory.
 *@param args List of args. args[0] is "cd". args[1] is the directory.
 *@return Always returns 1, to continue executing.
 */
int shell_cd(char **args)
{
	char *new_dir;

	char *current_dir = getcwd(NULL, 0);
	if (current_dir == NULL)
	{
		perror("shell");
		return (1);
	}

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		new_dir = getenv("HOME");
	}
	else if (strcmp(args[1], "-") == 0)
	{
		new_dir = getenv("OLDPWD");
	}
	else
	{
		new_dir = args[1];
	}

	if (chdir(new_dir) != 0)
	{
		perror("shell");
	}
	else
	{
		if (setenv("OLDPWD", current_dir, 1) != 0)
		{
			perror("shell");
		}
	}

	free(current_dir);
	return (1);
}

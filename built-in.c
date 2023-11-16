#include "simple_shell.h"

/**
 *_myenv - Print the current environment.
 *@info: Pointer to the shell information struct.
 *Return: Always 0 (success).
 */
int _myenv(info_t *info)
{
	char **env_list = info->env;

	while (*env_list)
	{
		printf("%s\n", *env_list);
		env_list++;
	}

	return (0);
}

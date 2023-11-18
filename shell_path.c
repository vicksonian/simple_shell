#include "shell.h"

/**
 * Get the full path of an executable by searching through
 * get_executable_path
 * the directories in the PATH environment variable.
 * @param command The name of the executable.
 * @return The full path of the executable if found,
 * or NULL if not found or in case of an error.
 */

char *get_executable_path(char *command)
{
	char *path_env = getenv("PATH");

	char *path_copy, *dir;

	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set.\n");
		return (NULL);
	}
	path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		char *full_path = malloc(strlen(dir) + strlen(command) + 2);

		if (full_path == NULL)
		{
			perror("malloc");
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

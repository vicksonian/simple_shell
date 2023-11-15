#include "simple_shell.h"

/**
 * Searches for the command in the directories
 * specified by the PATH environment variable.
 * @param command: The command to search for.
 * @return: Full path to the command if found, NULL otherwise.
 */
#include "simple_shell.h"

char *search_path(char *command)
{
	char *path = getenv("PATH");
char *path_copy, *token;
	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set.\n");
		return (NULL);
	}
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(command) + 2);
		
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

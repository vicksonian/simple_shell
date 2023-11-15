#include "simple_shell.h"

/**
 *read_line - Read a line of input from the user.
 *
 *Return: The line read from the user.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("read_line");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}

/**
 *split_line - Split a line into tokens.
 *
 *@line: The line to be split.
 *
 *Return: An array of tokens.
 */
char **split_line(char *line)
{
	const char *delimiters = " \t\r\n\a";
	size_t bufsize = MAX_INPUT_SIZE;
	size_t position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("split_line: allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delimiters);
	while (token != NULL)
	{
		tokens[position] = strdup(token);
		if (!tokens[position])
		{
			perror("split_line: strdup error");
			exit(EXIT_FAILURE);
		}

		position++;

		if (position >= bufsize)
		{
			bufsize += MAX_INPUT_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("split_line: reallocation error");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, delimiters);
	}

	tokens[position] = NULL;
	return (tokens);
}

/**
 *execute - Execute a command.
 *
 *@args: The command and its arguments.
 *
 *Return: 1 if the shell should continue running, 0 otherwise.
 */
int execute(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execute");
		}

		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("execute");
	}
	else
	{
		do { wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	(void)wpid;
	}

	return (1);
}

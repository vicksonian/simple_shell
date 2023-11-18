#include "shell.h"

/**
 * execute_command - Execute a command in a child process.
 *@command: The command to execute.
 *
 *This function forks a child process and uses execve to execute the specified
 *command in the child. The parent process waits for the child to complete and
 *returns 1 if the command was executed successfully, and 0 otherwise.
 *
 *Return: 1 on success, 0 on failure.
 */

void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		/*Child process */
		char *argv[2];
		char *envp[1];

		argv[0] = command;
		argv[1] = NULL;

		envp[0] = NULL;

		execve(command, argv, envp);
		perror("execve");
		_exit(EXIT_FAILURE);
	}
	else
	{
		/*Parent process */
		wait(NULL);
	}
}

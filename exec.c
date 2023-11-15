#include "simple_shell.h"

/**
* sigint_handler - Handles the SIGINT signal.
* @signo: The signal number.
*
* Description:
* This function handles the SIGINT signal, providing a simple action
* (currently doing nothing) when the signal is received.
*/


void sigint_handler(int signo)
{
	(void)signo;
	
}

/**
* execute_command - Executes a command with the given arguments.
* @command: The command to be executed.
*
* Return:
* Returns 1 if the command is executed successfully.
*/

int execute_command(char *command)
{
	pid_t pid, wpid;
	int status;

	if (signal(SIGINT, sigint_handler) == SIG_ERR)
	{
		perror("signal");
		exit(EXIT_FAILURE);
	}

int execute_command(char **args)
{

if (args[0] != NULL && strcmp(args[0], "exit") == 0)
       {
        // If it is, exit the shell
        printf("Exiting the shell\n");
        exit(EXIT_SUCCESS);
       }
}
	pid = fork();

	if (pid == 0)
	{
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("./shell");
			_exit(EXIT_FAILURE);
		}
	}
		else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	(void)wpid;

	return (0);
}

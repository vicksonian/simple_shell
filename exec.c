#include "shell.h"

/**
* Execute a command.
*
* This function takes an array of strings representing a command and its arguments.
* It forks a new process to execute the command using execvp and waits for the child
* process to complete in the parent process.
*
* @param args An array of strings representing the command and its arguments.
* @return 1 on success, or an error code on failure.
*/

int execute_command(char **args)
{
pid_t pid;
int status;

if (args[0] == NULL)
{
return (1); /* Empty command */
}

pid = fork();
if (pid == 0)
{
/* Child process */
if (execvp(args[0], args) == -1)
{
perror("shell");
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
perror("shell");
}
else
{
/* Parent process */
waitpid(pid, &status, WUNTRACED);
}

return (1);
}


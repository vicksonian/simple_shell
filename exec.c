#include "shell.h"
/**
 * execute_command - Executes a command with the given arguments.
 * @args: An array of strings representing the command and its arguments.
 *
 * Return:
 * Returns 1 if the command is executed successfully.
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


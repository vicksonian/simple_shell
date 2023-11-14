#include "shell.h"

/**
* execute_command - Execute the entered command
* @args: The command and its arguments
*/
 
void execute_command(char **args)
{
char *path = search_path(args[0]);
pid_t child_pid;
int status;

if (path == NULL)
{
fprintf(stderr, ":) %s: command not found\n", args[0]);
return;
}

child_pid = fork();
if (child_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}

if (child_pid == 0)
{
if (execve(path, args, NULL) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
waitpid(child_pid, &status, 0);
}

free(path);
}

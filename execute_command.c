#include "simple_shell.h"

/**
 * execute_command - Executes a command with the given arguments.
 * @args: An array of strings representing the command and its arguments.
 *
 * Return:
 * Returns 1 if the command is executed successfully.
 */
void sigint_handler(int signo)
{
(void)signo;
    
}

int execute_command(char *command)
{
pid_t pid, wpid;
int status;

    /* Set up signal handler for Ctrl+C*/
if (signal(SIGINT, sigint_handler) == SIG_ERR)
{
perror("signal");
exit(EXIT_FAILURE);
}

pid = fork();

if (pid == 0)
{
        
if (strchr(command, '/') == NULL)
{
fprintf(stderr, "./shell: No such file or directory\n");
_exit(EXIT_FAILURE);
}

if (execlp(command, command, (char *)NULL) == -1)
{
fprintf(stderr, "./shell: No such file or directory\n");
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
do
{
wpid = waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

(void)wpid;

return 0;
}

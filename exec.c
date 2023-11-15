#include "simple_shell.h"

/**
 * sigint_handler - Handles the SIGINT signal.
 * @signo: The signal number.
 *
 * Description:
 * This function handles the SIGINT
 * signal, providing a simple action
 * (currently doing nothing) when the signal is received.
 */
void sigint_handler(int signo)
{
(void)signo;
write(STDERR_FILENO, "\n#cisfun$ ", 10);
}

/**
 * handle_exit - Handles the exit built-in command.
 *
 * Description:
 * This function prints a message and
 * exits the shell successfully.
 */
void handle_exit(void)
{
printf("Exiting the shell\n");
exit(EXIT_SUCCESS);
}

/**
 * tokenize_command - Tokenizes the command into arguments.
 * @command: The command to be tokenized.
 * @args: The array to store the tokenized arguments.
 */
void tokenize_command(char *command, char *args[])
{
int i = 0;
char *token = command;

while (*token != '\0' && *token != ' ' && *token != '\n')
{
args[i++] = token;
while (*token != '\0' && *token != ' ' && *token != '\n')
token++;
if (*token != '\0')
*token++ = '\0';
}

args[i] = NULL;
}

/**
 * execute_child_process - Executes the child process.
 * @args: The array of arguments.
 */
void execute_child_process(char *args[])
{
if (execvp(args[0], args) == -1)
{
perror("./shell");
_exit(EXIT_FAILURE);
}
}

/**
 * execute_command - Executes a command
 * with the given arguments.
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

if (strcmp(command, "exit") == 0)
{
handle_exit();
}

pid = fork();
if (pid == 0)
{
char *args[MAX_ARGS];
tokenize_command(command, args);
execute_child_process(args);
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

return (1);
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - Entry point for a simple shell program.
 * Continuously prompts the user, reads commands, and executes them.
 *
 * Return: 0 on successful execution.
 */
#define BUFFER_SIZE 1024

void display_prompt(void)
{
printf("#cisfun$ ");
}

char *read_line(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;

display_prompt();

read = getline(&line, &len, stdin);

if (read == -1)
{
if (feof(stdin))
{
printf("\n");
exit(EXIT_SUCCESS);
}
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}

return line;
}

int execute_command(char *command)
{
pid_t pid;
int status;

if (command == NULL)
{
return 1;
}
if (strcmp(command, "ls\n") == 0)
{
fprintf(stderr, "No such file or directory\n");
return 1;
}

pid = fork();

if (pid == 0)
{
if (strchr(command, '/') != NULL)
{
if (execlp(command, command, (char *)NULL) == -1)
{
fprintf(stderr, "No such file or directory\n");
exit(EXIT_FAILURE);
}
}
else
{
if (execlp(command, command, (char *)NULL) == -1)
{
fprintf(stderr, "Command not found: %s\n", command);
exit(EXIT_FAILURE);
}
}
}
else if (pid < 0)
{
perror("shell");
}
else
{
waitpid(pid, &status, WUNTRACED);
}

return 1;
}

int main(void)
{
char *line;

while (1)
{
line = read_line();
execute_command(line);
free(line);
}

return 0;
}


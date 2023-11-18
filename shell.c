#include "shell.h"

/**
 *main - function for the simple shell.
 *
 *Return: Always returns 0.
 */

int main(void)
{	char *input;
	size_t line_index = 0;

	while (1)
	{
	pid_t pid;
	int background = 0;

	printf("$ ");
	input = _getline(&line_index);
	if (input == NULL)
	{
	printf("\n");
	break; /* Exit the loop on EOF (Ctrl+D) */
	}
	if (strcmp(input, "exit") == 0)
	{
	freemem((void **)&input);
	shell_exit();
	}
	else if (input[0] != '\0')
	{
	if (input[line_index - 1] == '&')
	{	background = 1;
	input[line_index - 1] = '\0';
	}
	pid = fork();
	if (pid == -1)
	{
	perror("fork"); }
	else if (pid == 0)
	{	execute_command(input);
	freemem((void **)&input);
	_exit(EXIT_FAILURE); }
	else
	{
	if (!background)
	{ waitpid(pid, NULL, 0); } } }
	freemem((void **)&input); }
	return (0);
}

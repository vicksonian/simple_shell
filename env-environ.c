#include "shell.h"
/**
 * split_line - Tokenizes a string into an array of strings.
 * @line: The input string to be tokenized.
 *
 * Return: An array of strings (tokens) obtained from the input line.
 */
char **split_line(char *line)
{
int buffer_size = BUFFER_SIZE, position = 0;
char **tokens = malloc(buffer_size * sizeof(char *));
char *token;

if (!tokens)
{
perror("shell");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\n");
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= buffer_size)
{
buffer_size += BUFFER_SIZE;
tokens = realloc(tokens, buffer_size *sizeof(char *));
if (!tokens)
{
perror("shell");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " \t\n");
}
tokens[position] = NULL;
return (tokens);
}


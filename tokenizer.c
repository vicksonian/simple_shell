#include "simple_shell.h"

/**
 *tokenize - Tokenize a line into an array of tokens.
 *
 *@line: The line to be tokenized.
 *
 *Return: An array of tokens.
 */
char **tokenize(char *line)
{
	const char *delimiters = " \t\r\n\a";
	char **tokens = NULL;
	char *token;
	int token_count = 0;

	tokens = malloc(sizeof(char *));
	if (!tokens)
	{
		perror("tokenize: allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delimiters);
	while (token != NULL)
	{
		tokens[token_count] = strdup(token);
		if (!tokens[token_count])
		{
			perror("tokenize: strdup error");
			exit(EXIT_FAILURE);
		}

		token_count++;

		tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
		if (!tokens)
		{
			perror("tokenize: reallocation error");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, delimiters);
	}

	tokens[token_count] = NULL;

	return (tokens);
}

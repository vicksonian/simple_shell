#include "shell.h"

/**
* is_delim - Check if a character is a delimiter.
* @c: The character to check.
* @delimiters: The set of delimiters.
*
* Return: 1 if the character is a delimiter, 0 otherwise.
*/

int is_delim(char c, const char *delimiters)
{
while (*delimiters)
{
if (*delimiters == c)
{
return (1);
}
delimiters++;
}
return (0);
}

/**
* split_string - Split a string into an array of words based on delimiters.
* @str: The input string.
* @delimiters: The set of delimiters.
*
* Return: An array of words.
*/

char **split_string(char *str, const char *delimiters)
{
int i, j, k, m, numwords = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
if (!delimiters)
delimiters = " ";
for (i = 0; str[i] != '\0'; i++)
{
if (!is_delim(str[i], delimiters) && (is_delim(str[i + 1],
delimiters) || !str[i + 1]))
numwords++;
}
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (is_delim(str[i], delimiters))
i++;
k = 0;
while (!is_delim(str[i + k], delimiters) && str[i + k])
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[i++];
s[j][m] = 0;
} s[j] = NULL;
return (s);
}

/**
* main - The main function.
*
* Return: 0 on success.
*/

int main(void)
{
char input[] = "This is a sample sentence.";
char **result = split_string(input, " ");

if (result != NULL)
{
int i;
for (i = 0; result[i] != NULL; i++)
{
printf("%s\n", result[i]);
free(result[i]);
}
free(result);
}
return (0);
}

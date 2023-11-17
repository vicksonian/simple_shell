#include "simple_shell.h"


/*
* _strncpy - Copy at most 'n' characters from 'src' to 'dest'.
*
* @dest: The destination buffer.
* @src: The source string.
* @n: The maximum number of characters to copy.
*
* Return: A pointer to the destination buffer 'dest'.
*/

char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	char *s = dest;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (s);
}

/**
* _strncat - Concatenate at most 'n' characters from 'src' to 'dest'.
* @dest: The destination buffer.
* @src: The source string.
* @n: The maximum number of characters to concatenate.
*
* Return: A pointer to the destination buffer 'dest'.
*/

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t i, j;
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	for (i = 0, j = 0; i < n && src[j] != '\0'; i++, j++)
	{
		dest[i] = src[j];
	}

	dest[i] = '\0';

	return (s);
}

/**
* _strchr - Locate the first occurrence of a character in a string.
* @s: The string to search.
* @c: The character to find.
*
* Return: A pointer to the first occurrence of 'c' in 's', or
* NULL if not found.
*/

char *_strchr(const char *s, int c)
{
	for (; *s != '\0'; ++s)
	{
		if (*s == c)
			return (char * (s));
	}

	return (NULL);
}

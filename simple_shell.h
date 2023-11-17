#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "$"
#define MAX_INPUT_SIZE 1024

char *read_line(void);
char **split_line(char *line);
int execute(char **args);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strncat(char *dest, const char *src, size_t n);
char *_strchr(const char *s, int c);
char **tokenize(char *line);
void _puts(char *str);
void display_prompt(void);

/* Prototype for the custom _getline function*/
ssize_t _getline(char **line, size_t *bufsize);

#endif /*_SHELL_H */

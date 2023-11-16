/* simple_shell.h */
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>

#define MAX_INPUT_SIZE 1024
#define MAX_PATH_SIZE 1024

/* Define info_t type */
typedef struct
{
    char **env;
    char **argv;
    int argc;
} info_t;

/* Function Declarations */
char *read_line(void);
char **split_line(char *line);
int execute(char **args);

/* String Manipulation Functions */
char *_strncpy(char *dest, const char *src, size_t n);
char *_strncat(char *dest, const char *src, size_t n);
char *_strchr(const char *s, int c);

int _myenv(info_t *info);
typedef struct list_s list_t;

#endif /* SHELL_H */

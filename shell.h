#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_INPUT_LENGTH 1024
#define BUFFER_SIZE 1024

typedef struct {
    char **env;
    int env_changed;
    char **environ;
} info_t;

void execute_command(char *command);
void shell_exit(void);
int shell_cd(char **args);
int shell_atoi(const char *str);
char *_getline(size_t *line_index);
int freemem(void **ptr);
char *_getline(size_t *line_index);

#endif

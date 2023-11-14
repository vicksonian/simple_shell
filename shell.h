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
#include <dirent.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_LINE 1024
#define MAX_ARGS 64

char *read_line(void);
char **split_line(char *line);
int execute_command(char **args);
void handle_signal(int signal);

#endif /* SHELL_H */

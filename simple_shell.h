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

/* Function Declarations */
char *read_line(void);
char **split_line(char *line);
int execute(char **args);

#endif /* SHELL_H */

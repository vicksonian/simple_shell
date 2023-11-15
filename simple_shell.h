#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void sigint_handler(int signo);
int execute_command(char *command);
char *read_line(void);

#endif /* SIMPLE_SHELL_H */


#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>

#define PROMPT "$ "
#define MAX_INPUT_LENGTH 1024


/*function for prompt*/
void prompt(void);

void execute_command(char *command);



#endif /*_SHELL_H_*/

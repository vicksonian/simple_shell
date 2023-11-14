#ifndef _SHELL_H_
#define _SHELL_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define buffer_size 1024
#define MAX_PATH 1024


/* Function Prototypes */
void display_prompt(void);
char *read_input(void);
void execute_command(char *command);
char *search_path(char *command);
char **tokenize_input(char *input);



#endif /* SHELL_H */

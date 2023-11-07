#ifndef _SHELL_H_
#define _SHELL_H_

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

/* Function Prototypes */
void shell_loop(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
char *_getenv(const char *name);
char *find_path(char *command, char **env);
int launch(char **args, char **env);
void exit_shell(char **args);
void print_env(char **env);
void env_shell(char **args, char **env);
char *own_getline(void);
void free_tokens(char **tokens);

#endif /* SHELL_H */

#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct {
    char *buffer;
    size_t size;
    size_t index;
} InputBuffer;

void input_buf(InputBuffer *input);
char *get_input(InputBuffer *input);
size_t read_buf(InputBuffer *input);
char *_getline(InputBuffer *input);


void *my_malloc(size_t size);
void *my_realloc(void *ptr, size_t size);
void my_free(void *ptr);


int execute_command(char *command);

#endif /* SIMPLE_SHELL_H */

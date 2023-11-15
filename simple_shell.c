#include "simple_shell.h"

int main(void)
{
    char *line;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        printf("#cisfun$ ");
        read = getline(&line, &len, stdin);

        if (read == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                free(line);
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        line[read - 1] = '\0'; /* Remove the newline character*/

        if (execute_command(line) == -1)
        {
            fprintf(stderr, "./shell: No such file or directory\n");
        }

        free(line);
        line = NULL;
    }

    return 0;
}

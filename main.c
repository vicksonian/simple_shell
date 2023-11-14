#include "shell.h"

int main(void)
{
char *input;

while (1)
{
display_prompt();
char *input = read_input();
execute_command(tokenize_input(input));
free(input);
}

return 0;
}


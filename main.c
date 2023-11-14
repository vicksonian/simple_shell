#include "shell.h"


/**
 * @brief Main function for the shell.
 *
 * This function runs an interactive shell that continuously prompts the user for input,
 * reads the input, tokenizes it, and executes the corresponding command.
 *
 * @return 0 on successful execution.
 */

int main(void)
{
char *input;

while (1)
{
display_prompt();
input = read_input();
execute_command(tokenize_input(input));
free(input);
}

return (0);
}

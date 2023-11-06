#include "shell.h"

/* Simple shell-like program:
 * - Displays a shell prompt.
 * - Reads a single line of input from the user.
 * - Prints the input line.
 */

void display_prompt(void)
{

    char *prompt = "shell";
    char *line;
    size_t bufsize = 0;

    printf("%s$ ", prompt);
    getline(&line, &bufsize, stdin);
    printf("%s\n", line);

    free(line);
}

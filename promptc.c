#include "shell.h"

/* prompt is display again if a command is executed */

int main(int argc, char **argv)
{
    /* declaring void variables */
    (void)argc;
    (void)argv;

    char *prompt = "shell";
    char *line;
    size_t bufsize = 0;

    while (1)
    {
        printf("%s$ ", prompt);
        getline(&line, &bufsize, stdin);
        printf("%s\n", line);

        /* free up allocated memory */
        free(line);
    }

    return 0;
}

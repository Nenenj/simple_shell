#include "shell.h"

/* prompt is display again if a command is executed */

int shell(int argc, char **argv)
{
    /* declaring void variables */
    (void)argc;
    (void)argv;

    char *prompt = "shell";
    char *line;
    size_t bufsize = 0;
    ssize_t nchars_read;

    /* Allocate memory for buffer */
    char *buffer = malloc(1024);
    memset(buffer, 0, 1024);

    while (1)
    {
        printf("%s$ ", prompt);
        nchars_read = getline(&buffer, &bufsize, stdin);

        /* check if the getline function failed or reached EOF or user use CTRL + D*/
        if (nchars_read == -1)
        {
            printf("Exiting shell....\n");
            break;
        }

        /* set the line pointer to the buffer */
        line = buffer;

        printf("%s\n", line);
    }

    /* free the allocated memory for the buffer */
    if (buffer != NULL)
    {
        /* free up allocated memory */
        free(buffer);
    }

    return 0;
}

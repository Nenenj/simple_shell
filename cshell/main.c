#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *prompt = "(cshell) $ ";
    char *lineptr;
    size_t len = 0;
    ssize_t mychar_input;

    /* declaring void variables */
    (void)argc;
    (void)argv;

    /* creating infinite loop */
    while (1)
    {
        printf("%s", prompt);
        mychar_input = getline(&lineptr, &len, stdin);
        /* Check for getline function failure, EOF, or Ctrl+D usage */
        if (mychar_input == -1)
        {
            printf("Exiting shell....\n");
            return (-1);
        }

        printf("%s\n", lineptr);

        /* free up allocated memory*/
        free(lineptr);
    }
    return (0);
}

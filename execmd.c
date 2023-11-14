#include "shell.h"
#include <stdlib.h>

extern char **environ;

void execmd(char **argv)
{
    char *command = NULL, *actualCommand = NULL;

    if (argv)
    {

        /* Get the command */
        command = argv[0];

        printf("Executing command: %s\n", command);

        /* check if the command is "env" */
        if (strcmp(command, "env") == 0)
        {
            /* Print the current environment */
            char **env = environ;
            while (*env != NULL)
            {
                printf("%s\n", *env);
                env++;
            }
        }
        else
        {

            /* generate the path to this command before passing it to execve */
            actualCommand = get_location(command);

            if (actualCommand != NULL)
            {
                printf("Full path to command: %s\n", actualCommand);

                /* execute command with execve */
                if (execve(actualCommand, argv, NULL) == -1)
                {
                    perror("Error:");
                }
            }
            else
            {
                printf("Command not found: %s\n", command);
            }
        }
    }
    else
    {
        printf("No command provided. \n");
    }
}
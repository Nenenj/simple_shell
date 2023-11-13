#include "shell.h"

void execmd(char **argv);

/* prompt is displayed again if a command is executed */

int shell(void)
{
    char *prompt = "shell";
    char *line = NULL, *line_copy = NULL;
    size_t bufsize = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;

    char **cmdArgs = NULL;

    /* create a loop for the shell prompt*/
    while (1)
    {
        printf("%s$ ", prompt);
        nchars_read = getline(&line, &bufsize, stdin);
        /* check if the getline function failed or reached EOF or user use CTRL + D*/
        if (nchars_read == -1)
        {
            printf("Exiting shell....\n");
            return (-1);
        }

        /* allocate space for a copy of the line */
        line_copy = malloc(sizeof(char) * nchars_read);
        if (line_copy == NULL)
        {
            perror("tsh memory allocation error");
            return (-1);
        }

        /* copy line to line_copy */
        strcpy(line_copy, line);

        /***** split the string (line) into an array of words *****/
        /* calculate the total number of tokens */
        token = strtok(line, delim);

        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        /* Allocate space to hold the array of strings */
        cmdArgs = malloc(sizeof(char *) * num_tokens);

        /* store each of the token in the argv array */
        token = strtok(line_copy, delim);

        for (i = 0; token != NULL; i++)
        {
            cmdArgs[i] = malloc(sizeof(char) * strlen(token));
            strcpy(cmdArgs[i], token);

            token = strtok(NULL, delim);
        }
        cmdArgs[i] = NULL;

        /* execute the command */
        execmd(cmdArgs);
    }

    /* free up allocated memory for cmdArgs */
    for (i = 0; i < num_tokens; i++)
    {
        free(cmdArgs[i]);
    }
    free(cmdArgs);

    /* free up allocated memory for line_copy and line */
    free(line_copy);
    free(line);

    return 0;
}

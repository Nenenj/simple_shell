#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
void execute_env(void)
{
	print_environment();
}

/**
 * shell - Run the shell prompt.
 *
 * Return: Always 0.
 */

int main(int argc, char **cmdArgs)
{

	char *prompt = "shell";
	char *line = NULL, *line_copy = NULL;
	size_t bufsize = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	/* declaring void variables */
	(void)argc;

	/* create an infinite loop */
	while (1)
	{
		printf("%s$ ", prompt);
		nchars_read = getline(&line, &bufsize, stdin);
		/* handle the end of file condition */
		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}

		/* allocate space for a copy of the line */
		line_copy = malloc(sizeof(char) * nchars_read);
		if (line_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		/* copy line to line_copy */
		strcpy(line_copy, line);
		/* split the string into an array of words */
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

		/* store each token in the cmdArgs array */
		token = strtok(line_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			cmdArgs[i] = malloc(sizeof(char) * strlen(token));
			strcpy(cmdArgs[i], token);

			token = strtok(NULL, delim);
		}

		if (strcmp(cmdArgs[0], "env") == 0)
		{
			execute_env();
			continue;
		}
		cmdArgs[i] = NULL;

		/* execute the command */
		execmd(cmdArgs);

		/* Free up allocated memory */
		free(line_copy);
		free(line);
	}
	return (0);
}

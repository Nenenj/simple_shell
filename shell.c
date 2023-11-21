#include "shell.h"
#include <stdio.h>

/* Placeholder for isInteractiveMode function */
int isInteractiveMode(info_t *info)
{

	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/* Placeholder for execute_command function */
int execute_command(char *command)
{
	printf("Executing command: %s\n", command);
	return (0);
}

/* Implementation of the shell function */
int shell(void)
{
	info_t info;
	char buffer[1024];

	/* Check if the shell is in interactive mode */
	if (isInteractiveMode(&info))
	{
		/* Interactive mode */
		printf("($) ");

		while (fgets(buffer, sizeof(buffer), stdin))
		{
			/* Remove newline character from input */
			buffer[strcspn(buffer, "\n")] = '\0';

			/* Execute the command */
			execute_command(buffer);

			printf("($) ");
		}
	}
	else
	{
		/* Non-interactive mode */

		/* Read from stdin (piped input) */
		while (fgets(buffer, sizeof(buffer), stdin))
		{
			/* Remove newline character from input */
			buffer[strcspn(buffer, "\n")] = '\0';

			/* Execute the command */
			execute_command(buffer);
		}
	}

	/* Return success */
	return (0);

}

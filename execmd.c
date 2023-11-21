#include "shell.h"

/**
 * execmd - Execute a command.
 * @argv: Array of command arguments.
 */
void execmd(char **cmdArgs)
{
	char *command = NULL, *actual_command = NULL;

	if (cmdArgs)
	{

		/* Get the command */
		command = cmdArgs[0];

		/* generate the path to this command before passing it to execve */
		actual_command = get_location(command);

		/* execute the actual_command with execve */
		if (execve(actual_command, cmdArgs, NULL) == -1)
		{
			perror("Error");
		}
	}
}

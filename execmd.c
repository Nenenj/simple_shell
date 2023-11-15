#include "shell.h"

/**
 * print_environment - Print the current environment.
 */
void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * execute_command - Execute a command with execve.
 * @command: The command to execute.
 * @argv: Array of command arguments.
 */
void execute_command(char *command, char **argv)
{
	char *actual_command = get_location(command);

	if (actual_command != NULL)
	{
		printf("Full path to command: %s\n", actual_command);

		/* Execute command with execve */
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		printf("Command not found: %s\n", command);
	}
}

/**
 * execmd - Execute a command.
 * @argv: Array of command arguments.
 */
void execmd(char **argv)
{
	char *command = NULL;

	if (!argv)
	{
		printf("No command provided.\n");
		return;
	}

	/* Get the command */
	command = argv[0];

	printf("Executing command: %s\n", command);

	/* Check if the command is "env" */
	if (strcmp(command, "env") == 0)
	{
		/* Print the current environment */
		print_environment();
	}
	else
	{
		/* Execute the command */
		execute_command(command, argv);
	}
}

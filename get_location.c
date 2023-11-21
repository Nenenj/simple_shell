#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/*
 * FindCommandLocation - Locate the full path of a command.
 *
 * Parameters:
 *   command: The command to locate.
 *
 * Returns:
 *   - The full path of the command if found, otherwise NULL.
 */
char *get_location(char *command)
{
	char *path, *pathCopy, *pathToken, *filePath;
	int commandLength, directoryLength;
	struct stat buffer;

	/* Get the value of the PATH environment */
	path = getenv("PATH");

	if (path)
	{
		/* Duplicate the path string */
		pathCopy = strdup(path);
		/* Get the length of the command that was passed */
		commandLength = strlen(command);

		/* Break down the path variable and get all the directories available */
		pathToken = strtok(pathCopy, ":");

		while (pathToken != NULL)
		{
			/* Get the length of the directory */
			directoryLength = strlen(pathToken);
			/* Allocate memory for storing the command line together with the directory name */
			filePath = malloc(commandLength + directoryLength + 2);
			/* Copy the directory path and concatenate the command to it */
			strcpy(filePath, pathToken);
			strcat(filePath, "/");
			strcat(filePath, command);
			strcat(filePath, "\0");

			/* Test if the file Path exists and return it if it does otherwise by the next directory */
			if (stat(filePath, &buffer) == 0)
			{
				/* free up allocated memory before returning the file_path */
				free(pathCopy);

				return (filePath);
			}
			else
			{
				/* free up the filePath memory for another path*/
				free(filePath);
				pathToken = strtok(NULL, ":");
			}
		}

		/* free up the memory */
		free(pathCopy);

		if (stat(command, &buffer) == 0)
		{
			return (command);
		}

		return (NULL);
	}

	return (NULL);
}

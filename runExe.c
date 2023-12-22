#include "shell.h"

/**
 * runExecve - handles execve to run commands
 * @args: the arguments to be handled
 */
void runExe(char *args[])
{
	char *token, *command;
	char *path = getenv("PATH");
	char *pathCopy;

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found\n");
		exit(EXIT_FAILURE);
	}

	pathCopy = strdup(path);

	if (pathCopy == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(pathCopy, ":");
	while (token != NULL)
	{
		
		command = malloc(strlen(token) + strlen(args[0]) + 2);
		if (command == NULL)
		{
			perror("Error allocating memory");
			exit(EXIT_FAILURE);
		}
		sprintf(command, "%s/%s", token, args[0]);
	
		execve(command, args, NULL);

		free(command);

		token = strtok(NULL, ":");
	}

	perror("Error executing command");
	exit(EXIT_FAILURE);
}

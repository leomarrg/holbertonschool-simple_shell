#include "shell.h"

char **environ;

/**
 * runExe - handles execve to run commands
 * @command: input commands from user
 * @args: the arguments to be handled
 */
void runExe(char *command, char *args[])
{
	if (execve(command, args, environ) == -1)
	{
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}

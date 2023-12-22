#include "shell.h"

/**
 * exeCmd - function that executes commands in simple shell
 * @command: takes the user input
 * @executable: used to print the exe file name
 * Return: returns nothing
*/

void exeCmd(char *command)
{
	pid_t pid;
	int status, i;
	char *token, *argv[MAX_ARGS], cmdCopy;

	cmdCopy = strdup(cmdCopy);
	token = strtok(command, " ");
	i = 0;

	if (cmdCopy == NULL)
	{
		perror("Error duplicating command");
		exit(EXIT_FAILURE);
	}

	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}

	argv[i] = NULL;

	pid = fork();

	if (pid == 0)
	{
		runExe(argv);
	}

	else if (pid == -1)
	{
		perror("Error forking");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error waiting for child process");
			exit(EXIT_FAILURE);
		}
	}
	free(cmdCopy);
}

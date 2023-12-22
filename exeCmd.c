#include "shell.h"

/**
 * exeCmd - function that executes commands in simple shell
 * @command: takes the user input
 * @executable: used to print the exe file name
 * Return: returns nothing
*/

void exeCmd(char *command, char *executable)
{
	pid_t pid;
	int status, i;
	char *path;
	size_t pathLen;
	char *envp[MAX_ARGS + 1];

	path = getenv("PATH");

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found\n");
		return;
	}

	pathLen = strlen(path);
	envp[0] = malloc(pathLen + 6);

	if (envp[0] == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	strcpy(envp[0], "PATH=");
	strcat(envp[0], path);
	envp[1] = NULL;

	pid = fork();
	if (pid == 0)
	{
		char *token, *argv[MAX_ARGS];

		token = strtok(command, " ");
		i = 0;

		while (token != NULL)
		{
			argv[i] = token;
			i++;
			token = strtok(NULL, " ");
		}

		argv[i] = NULL;

		if (execve(argv[0], argv, envp) == -1)
		{
			perror(executable);
			exit(EXIT_FAILURE);
		}
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

	free(envp[0]);
}

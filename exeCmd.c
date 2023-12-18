#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * exe_cmd - function executes the commands
 * @cmd: receives the input
 * Return: returns nothing
*/

void exe_cmd(char *cmd)
{
	pid_t pid;
	int status, i;
	char *argv[2];
	char *token;

	i = 0;
	argv[0] = cmd;
	argv[1] = NULL;
	token = strtok(cmd, " ");

	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("leomar@simple-shell\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("leomar@simple-shell\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("\n");
		waitpid(pid, &status, 0);
	}
}


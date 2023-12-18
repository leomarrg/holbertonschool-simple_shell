#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "shell.h"

/**
 * main - main function of simple shell program
 * Return: returns 0 if ran succesfully
*/

int main(void)
{
	char *input;
	size_t len;
	ssize_t read;

	len = 0;
	input = NULL;

	signal(SIGINT, handleSig);

	while (1)
	{
		printf("leomar@simple-shell> ");

		read = getline(&input, &len, stdin);
		if (read == -1)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		input[read - 1] = '\0';
		exe_cmd(input);
	}
		free(input);
		/*

		if (strlen(input) == 0)
		{
			continue;
		}

		token = strtok(input, " ");

		if (token != NULL)
		{
			exe_cmd(token);
		}
		else
		{
			printf("No command found.\n");
		}*/
	return (0);
}


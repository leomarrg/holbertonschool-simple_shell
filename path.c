#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define MAX_ARGS 64
#define MAX_PATH_LENGTH 1024
/**
 * parse_command - puts user input into separate commands
 * @input: input var
 * @args: arguments
 */
void parse_command(char *input, char **args)
{
	char *token;
	int i = 0;

	token = strtok(input, " \t\n");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
}
/**
 * find_executable - finds the executable
 * @command: commands
 * @paths: gives path
 * Return: NULL
 */
char *find_executable(char *command, char *paths)
{
	char *path;
	char *token;
	char *executable = (char *)malloc(MAX_PATH_LENGTH);

	token = strtok(paths, ":");
	while (token != NULL)
	{
		sprintf(executable, "%s%s", token, command);
		if (access(executable, X_OK) == 0)
		{
		return (executable);
		}
		token = strtok(NULL, ":");
	}

	free(executable);
	return (NULL);
}
/**
 * execute_command - makes command executable
 * @args: gives arguments
 * @paths: gives paths
 */
void execute_command(char **args, char *paths)
{
	char *executable = find_executable(args[0], paths);

	if (executable != NULL)
		if (strcmp(args[0], "ls") == 0)
		{
		execv("/bin/ls", args);
		}
		else
		{
			execv(executable, args);
		}
	else
	{
		printf("Command '%s' not found\n", args[0]);
	}
}
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char input[MAX_PATH_LENGTH];
	char *args[MAX_ARGS];
	char *path = getenv("PATH");

	while (1)
	{
		printf("Enter a command (or 'exit; to quit): ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		if (strcmp(input, "exit\n") == 0)
		{
			break;
		}
		parse_command(input, args);
		execute_command(args, path);
	}
	return (0);
}

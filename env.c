#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100
/**
 * print_env - prints environment vars
 * @envp: char in use
 */
void print_env(char *envp[])
{
	for (int i = 0; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
	}
}
/**
 * exeCmd - function that executes the command
 * @command: command to execute
 * @executable: executes
 * @envp: current environment vars
 */
void exeCmd(char *command, char *executable, char *envp[])
{
	pid_t pid, wpid;
	int status, i;

	pid = fork();
	if (pid == 0)
	{
	else
		if (pid < 0)
		{
			perror("Error forking");
			exit(EXIT_FAILURE);
		}
		else
		{
			do {
				wpid = wait(&status);
			} while (wpid != pid);
		}
	}
}
/**
 * main - entry point
 * @argc: arg count
 * @argv: array of pointers
 * @envp: environment vars
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char *argv[], char *envp[])
{
	char *input = NULL;
	size_t len = 0;

	signal(SIGINT, handleSig);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			display_prompt();
		}

		if (getline(&input, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(input);
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "env") == 0)
		{
			print_env(envp);
		}
		else
		{
			exeCmd(input, argv[0], envp);
		}
	}

	return (0);
}

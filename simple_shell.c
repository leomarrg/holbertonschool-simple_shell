#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

/**
 * display_prompt - function that prints on screen
 * Return: returns nothing
*/

void display_prompt(void)
{
	write(STDOUT_FILENO, "leomar@simple-shell$ ", 21);
	fflush(stdout);
}

/**
 * exeCmd - function that executes commands in simple shell
 * @command: takes the user input
 * @executable: used to print the exe file name
 * Return: returns nothing
*/

void exeCmd(char *command, char *executable)
{
	pid_t pid, wpid;
	int status;
	char *envp[] = {NULL};

	pid = fork();
	if (pid == 0)
	{
		char **argv;

		argv = malloc(sizeof(char *) * 2);
		argv[0] = command;
		argv[1] = NULL;

		if (execve(command, argv, envp) == -1)
		{
			perror(executable);
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do {
			wpid = wait(&status);
		} while (wpid != pid);
	}
}

/**
 * handleSig - handles the ctrl+c input
 * @signum: status of signal
 * Return: returns nothing
*/

void handleSig(int signum)
{
	(void) signum;
	write(STDOUT_FILENO, "\n", 1);
	display_prompt();
}

/**
 * main - main function in program
 * @argc: agrs count
 * @argv: argument vector
 * Return: return nothings
*/

int main(__attribute__((unused)) int argc, char *argv[])
{
	char *input = NULL;
	size_t len = 0;

	signal(SIGINT, handle_signal);

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

		exeCmd(input, argv[0]);
	}

	return (0);
}

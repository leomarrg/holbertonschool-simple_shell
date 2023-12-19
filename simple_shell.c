#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void display_prompt(void) {
	write(STDOUT_FILENO, "leomar@simple-shell$ ", 21);
	fflush(stdout);
}

void execute_command(char *command) {
	pid_t pid, wpid;
	int status;
	char *envp[] = {NULL};

	pid = fork();
	if (pid == 0) {
		char **argv = malloc(sizeof(char *) * 2);
		argv[0] = command;
		argv[1] = NULL;

		if (execve(command, argv, envp) == -1) {
			perror(command);
			free(argv);
			exit(EXIT_FAILURE);
		}
	} else if (pid < 0) {
		perror("fork");
	} else {
		do {
			wpid = wait(&status);
		} while (wpid != pid);
	}
}

void handle_signal(int signum) {
	(void) signum;
	write(STDOUT_FILENO, "\n", 1);
	display_prompt();
}

int main(void) {
	char *input = NULL;
	size_t len = 0;

	signal(SIGINT, handle_signal);

	while (1) {
		if (isatty(STDIN_FILENO)) {
			display_prompt();
		}

		if (getline(&input, &len, stdin) == -1) {
			if (isatty(STDIN_FILENO)) {
				write(STDOUT_FILENO, "\n", 1);
			}
			free(input);
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		execute_command(input);
	}

	return 0;
}

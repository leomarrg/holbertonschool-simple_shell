#include "shell.h"

/**
 * main - main function in program
 * @argc: agrs count
 * @argv: argument vector
 * Return: return nothings
*/

int main(void)
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

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}

		exeCmd(input);
		free(input);
		input = NULL;
	}

	return (0);
}

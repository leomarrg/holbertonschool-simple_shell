#include "shell.h"

/**
 * validCmd - checks if command is valid
 * @command: input from func exeCmd
 * Return: returns 0 if command is not valid & 1 if valid
*/

int validCmd(char *command)
{
	if (command == NULL)
		return (0);
	if (strlen(command) > 1024)
		return (0);

	return (1);
}

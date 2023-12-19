#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
/**
 * exeCmd - fucntion that executes the command
 * @command: command to be executed
 * @executable: executable
 */
void exeCmd(char *command, char *executable)
{
	char *envp[] = {

		"PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin",
		NULL
	};
}

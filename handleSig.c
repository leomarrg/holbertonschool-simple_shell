#include "shell.h"

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

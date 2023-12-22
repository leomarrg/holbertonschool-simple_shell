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

/**
 * display_prompt - function that prints on screen
 * Return: returns nothing
*/

void display_prompt(void)
{
	write(STDOUT_FILENO, "leomar@simple-shell$ ", 21);
	fflush(stdout);
}

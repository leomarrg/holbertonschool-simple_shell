#include "shell.h"

/**
 * display_prompt - function that prints on screen
 * Return: returns nothing
*/

void display_prompt(void)
{
	write(STDOUT_FILENO, "leomar@simple-shell$ ", 21);
	fflush(stdout);
}

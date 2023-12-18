#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "shell.h"

/**
 * handleSig - handles ctrl+c
 * @sigNum: receives input when ctr;+c is typed
 * Return: returns nothing
*/

void handleSig(__attribute__((unused)) int sigNum)
{
	printf("\nFile or directory not found.\n");
	printf("leomar@simple-shell> ");
	fflush(stdout);
}


#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100

void display_prompt(void);
void exeCmd(char *command);
void handleSig(int signum);
int validCmd(char *command);
void runExe(char *args[]);

#endif

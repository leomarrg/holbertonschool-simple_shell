#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 * @environ: global var
 */
void clearEnvironmentAndExecuteEnv(void)
{
	char **new_env = (char **)malloc(sizeof(char *));

	new_env[0] = NULL;

	environ = new_env;

	char *args[] = {"env", NULL};

	if (execvp("env", args) == -1)
	{
		perror("execvp");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	clearEnvironmentAndExecuteEnv();
	return (0);
}

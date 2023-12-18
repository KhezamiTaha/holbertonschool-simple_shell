#include "sh.h"

void execute(char *command, char *env[])
{
	pid_t child_pid;
	int status;
	char *token;
	char *args[32];
	int i = 0;
	int j;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{

		token = strtok(command, " ");
		while (token)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		for (j = 0; args[j] != NULL; j++)
		{
		}

		execvp(args[0], args);

		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}

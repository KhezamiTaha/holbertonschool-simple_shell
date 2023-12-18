#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int pid, status;
	char *lineptr = NULL;
	size_t n;
	char *argv[2];
	char *env[] = {NULL};
	int argc = 0;
	char *token;
	while (1)
	{
		printf("Simple Shell# ");
		fflush(stdout);

		getline(&lineptr, &n, stdin);
		lineptr[strlen(lineptr) - 1] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{

			token = strtok(lineptr, " ");
			while (token)
			{
				argv[argc++] = token;
				token = strtok(NULL, " ");
			}

			execve(argv[0], argv, env);

			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{

			wait(&status);
		}
	}

	free(lineptr);

	return 0;
}

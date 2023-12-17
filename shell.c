#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	int pid, status;
	char *lineptr = NULL;
	size_t n;
	char *argv[] = {lineptr, NULL};
	char *env[] = {NULL};

	printf("Simple Shell# ");
	fflush(stdout);
	pid = fork();
	if (pid == 0)
	{
		getline(&lineptr, &n, stdin);
		lineptr[strlen(lineptr) - 1] = '\0';
		argv[0] = lineptr;
		execve(lineptr, argv, env);
	}
	else
	{
		wait(&status);
	}

	return (0);
}

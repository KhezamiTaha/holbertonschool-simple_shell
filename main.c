#include "shell.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[], char *env[])
{

	int pid, status;
	char *lineptr;

	while (true)
	{
		printf("Simple Shell# ");
		fflush(stdout);
		pid = fork();
		if (pid == 0)
		{
			lineptr = _getline();

			execute(lineptr, env);
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}

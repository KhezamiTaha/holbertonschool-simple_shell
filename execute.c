#include "shell.h"
/**
 * main - execve               example
 *
 * Return: Always 0.
 */
int execute(char *lineptr, char *env[])
{
	char *argv[2];

	argv[0] = lineptr;
	argv[1] = NULL;
	execve(lineptr, argv, env);

	return (0);
}

#include "shell.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */
char *_getline(void)
{
	char *lineptr;
	size_t n;

	getline(&lineptr, &n, stdin);
	lineptr[strlen(lineptr) - 1] = '\0';

	return (lineptr);
}

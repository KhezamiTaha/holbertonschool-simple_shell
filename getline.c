#include "shell.h"
/**
 * _getline - read the line without the Null caracter
 *
 * Return: the poiter to the line or NULL if failure
 */
char *_getline(void)
{
	char *lineptr = NULL;
	size_t n;
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
	read = getline(&lineptr, &n, stdin);
	if (read == -1)
	{
		
		free(lineptr);
		return (NULL);
	}
	lineptr[strlen(lineptr) - 1] = '\0';

	return (lineptr);
}

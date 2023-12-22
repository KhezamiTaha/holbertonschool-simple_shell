#include "sh.h"
/**
 * handle_spaces - Removes leading spaces from a string.
 * @lineptr: The input string to process.
 * Return: If the modified string is not empty,
 * returns a pointer to the modified string;
 * otherwise, returns NULL.
 */
char *handle_spaces(char *lineptr)
{
	int length, i, j;

	length = strlen(lineptr);

	for (i = 0; i < length && lineptr[i] == ' '; i++)
	{
	}

	if (lineptr[i] == '\0')
		return (NULL);

	for (j = 0; i < length; i++, j++)
	{
		lineptr[j] = lineptr[i];
	}

	lineptr[j] = '\0';
	return (lineptr);
}

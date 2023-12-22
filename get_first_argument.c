#include "sh.h"
/**
 * get_first_argument - get the first argument of a string before space.
 *
 * Return: first argument or null if error.
 */
char *get_first_argument(char *lineptr)
{
	char *copy, *token;
	copy = strdup(lineptr);
	if (copy == NULL)
	{
		perror("ERROR");
		return (NULL);
	}
	token = strtok(copy, " ");
	return (token);
}
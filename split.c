#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int split()
{
	char *lineptr = NULL;
	size_t n, j;
	char *token;

	printf("$ ");
	getline(&lineptr, &n, stdin);
	lineptr[strlen(lineptr) - 1] = '\0';
	for (j = 0; token != NULL; j++, lineptr = NULL)
	{
		token = strtok(lineptr, " ");
		if (token != NULL)
			printf("%lu: %s\n", strlen(token), token);
		else
			break;
	} 

	return (0);
}

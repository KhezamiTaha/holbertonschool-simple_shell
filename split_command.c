#include "shell.h"
char **split_command(char *lineptr)
{

	int i = 0;
	char *token;
	char **array_command_splitted;

	array_command_splitted = malloc(sizeof(char *) * 1024);
	if (array_command_splitted == NULL)
	{
		perror("malloc array");
		return (NULL);
	}

	token = strtok(lineptr, " ");
	while (token != NULL)
	{
		array_command_splitted[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(array_command_splitted[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	array_command_splitted[i] = NULL;
	return (array_command_splitted);
}

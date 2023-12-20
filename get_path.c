#include "sh.h"
/**
 * find_path - find the correct path of the command
 *
 *
 * Return: the full path of the command or NULL in failure
 */
char *find_path(char *command)
{
	char *path_copy, *token, *path_env;
	struct stat st;

	path_env = getenv("PATH");
	if (path_env == NULL)
	{
		perror("PATH");
		return (NULL);
	}
	path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("ERROR");
		return (NULL);
	}
	token = strtok(path_copy, ":");
	while (token)
	{
		char full_path[1024];

		sprintf(full_path, "%s/%s", token, command);

		if (stat(full_path, &st) == 0)
		{
			command = full_path;
			return (command);
		}

		token = strtok(NULL, ":");
		}

	return (NULL);
}

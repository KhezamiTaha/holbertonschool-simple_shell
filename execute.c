#include "sh.h"
/**
 * execute - Executes a command using fork and execve.
 * @command: The command string to be executed.
 *
 * Return: No return value.
 *         Prints error messages if fork or execve fails.
 */
int execute(char *command)
{
	pid_t child_pid;
	int status, n;
	char *token, *full_path;
	char **args;
	char *_env[] = {NULL};
	int i = 0;
	struct stat st;

	args = malloc(sizeof(char *) * 1024);
	if (args == NULL)
	{
		perror("malloc array");
		return (1);
	}

	token = strtok(command, " ");
	while (token != NULL)
	{
		args[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(args[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		freeArray(args);
		return (-1);
	}
	if (child_pid == 0)
	{

		if (stat(args[0], &st) == 0)
		{
			execve(args[0], args, _env);
		}
		else
		{
			full_path = find_path(args[0]);
			if (full_path != NULL)
				args[0] = full_path;
			else
			{
				freeArray(args);
				return (-1);
			}
			n = execve(full_path, args, _env);
			if (n == -1)
			{
				freeArray(args);
				return (-1);
			}
		}
	}
	else
	{
		wait(&status);
		freeArray(args);
	}

	return (0);
}

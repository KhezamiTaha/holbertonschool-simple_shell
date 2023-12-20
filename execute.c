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
	char *args[32];
	char *_env[] = {NULL};
	int i = 0;
	struct stat st;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (child_pid == 0)
	{
		token = strtok(command, " ");
		while (token)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (stat(args[0], &st) == 0)
		{
			execve(args[0], args, _env);
		}
		else
		{
			full_path = find_path(args[0]);
			args[0] = full_path;
			n = execve(args[0], args, _env);
			if (n == -1)
				return (0);

			perror("in the child");
		}
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
		perror("in the par afterrrrr");
	}
	return (0);
}

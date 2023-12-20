#include "shell.h"
/**
 * execute - execve  the command in the current process
 *@lineptr: the line read
 *@env: the environement
 * Return: Always 0.
 */
int execute(char **complet_command, char *env[])
{
	int pid, status, n;


	pid = fork();
	if (pid == 0)
	{
		n = execve(complet_command[0], complet_command, env);
		if (n == -1)
			return (-1);
	}
	else
	{
		wait(&status);
	}

	return (0);
}

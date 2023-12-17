#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *lineptr = argv[1];
	int i = 0, pid, statuus;
	char *args[] = {"/usr/local/bin/betty", lineptr, NULL};
	char *env[] = {NULL};

	while (i < 1)
	{
		pid = fork();
		if (pid == 0)
			execve("/usr/local/bin/betty", args, env);
		else
		{
			wait(&statuus);
			i++;
		}
	}
	return (0);
}

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *lineptr = "/bin/ls";
	int i = 0, pid, statuus;
	char *argv[] = {"/usr/local/bin/betty", NULL};
	char *env[] = {NULL};

	while (i < 1)
	{
		pid = fork();
		if (pid == 0)
			execve("/usr/local/bin/betty", argv, env);
		else
		{
			wait(&statuus);
			i++;
		}
	}
	return (0);
}
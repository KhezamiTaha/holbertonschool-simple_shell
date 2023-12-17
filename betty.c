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

	int i = 0, pid, statuus;
	char *args[3];
	char *env[] = {NULL};
	(void)(argc);

	while (i < 1)
	{
		pid = fork();
		if (pid == 0)
		{
			args[0] = "/usr/local/bin/betty";
			args[1] = argv[1];
			args[2] = NULL;
			execve("/usr/local/bin/betty", args, env);
		}
		else
		{
			wait(&statuus);
			i++;
		}
	}
	return (0);
}

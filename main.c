#include "shell.h"
/**
 * main - execve example
 *@argc: the number of arguments
 *@argv: the array of arguments
 *@env: the environement
 * Return: Always 0.
 */
int main(int argc, __attribute__((unused)) char *argv[], char *env[])
{
	int n;
	char *lineptr;
	char **complet_command;
	(void)argc;
	(void)env;

	while (true) /*  */
	{

		lineptr = _getline();
		if (lineptr == NULL) /*  Ctrl + D  ==>  exit */
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			return (0);
		}

		complet_command = split_command(lineptr);


		 n = execute(complet_command, env);
	   if (n == -1)
	   {
		   free(lineptr);
		   return (0);
	   }

	   free(lineptr); 
	}

	return (0);
}

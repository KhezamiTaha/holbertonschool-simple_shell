#include "sh.h"
/**
 * main - The main function of the simple shell.
 *
 * Return: Always returns 0.
 *         Exits the program when the user enters "exit".
 */
int main(void)
{
	char *lineptr;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}
		lineptr = my_getline();
		if (lineptr == NULL)
		{
			write(STDOUT_FILENO, "\n",1);
			return (0);
		}
		if (strcmp(lineptr, "env") == 0)
		{
			print_env();
		}
		else if (strcmp(lineptr, "exit") == 0)
		{
			exit_shell();
		}
		else
		{
			execute(lineptr);
		}

		free(lineptr);
	}

	return (0);
}

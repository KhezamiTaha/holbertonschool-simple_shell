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
	int n;
	struct stat st;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}
		lineptr = my_getline();
		if (stat(lineptr, &st) == 0)
		{
			return (0);
		}

		if (lineptr == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			return (0);
		}

		if (strcmp(lineptr, "env") == 0)
		{
			print_env();
		}

		else if (strcmp(lineptr, "exit") == 0)
		{
			free(lineptr);
			exit_shell();
		}

		else
		{
			n = execute(lineptr);
			if (n == -1)
			{
				free(lineptr);
				return (0);
			}
			/*else if (n == -2)*/
		}

		free(lineptr);
	}

	return (0);
}

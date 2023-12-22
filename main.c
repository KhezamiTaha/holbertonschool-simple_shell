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

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		lineptr = my_getline();
		if (lineptr == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			return (0);
		}

		if (*lineptr == ' ')
		{
			lineptr = handle_spaces(lineptr);
		}
		
		if (lineptr == NULL)
		{
			free(lineptr);
			continue;
		}

		if (strcmp(lineptr, "env") == 0)
		{
			print_env();
		}

		else if (strcmp(lineptr, "exit") == 0)
		{
			free(lineptr);
			exit(2);
		}

		else
		{
			n = execute(lineptr);
			if (n == -1)
			{
				free(lineptr);
				return (0);
			}
		}

		free(lineptr);
	}
	return (0);
}

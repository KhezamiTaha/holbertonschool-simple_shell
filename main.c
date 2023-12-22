#include "sh.h"
/**
 * main - The main function of the simple shell.
 *
 * Return: Always returns 0.
 *         Exits the program when the user enters "exit".
 */
int main(int argc, char *argv[])
{
	
	int n, counter = 0;
	char *lineptr, *first_argument;
	(void) argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		counter++;
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
		first_argument = get_first_argument(lineptr);

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
				printf("%s: %d: %s: not found\n", argv[0], counter, first_argument);
				free(lineptr);
				return (0);
			}
		}

		free(lineptr);
	}
	return (0);
}

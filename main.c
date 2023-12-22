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
	char *lineptr, *first_argument, *line_no_space;
	(void)argc;

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
			line_no_space = handle_spaces(lineptr);
			if (line_no_space == NULL)
			{
				free(lineptr);
				continue;
			}
		}
		else
			line_no_space = lineptr;

		first_argument = get_first_argument(line_no_space);

		if (strcmp(line_no_space, "env") == 0)
		{
			print_env();
		}

		else if (strcmp(line_no_space, "exit") == 0)
		{
			free(first_argument);
			free(line_no_space);
			exit(2);
		}

		else
		{
			n = execute(line_no_space);
			if (n == -1)
			{
				printf("%s: %d: %s: not found\n", argv[0], counter, first_argument);
				free(first_argument);
				free(lineptr);
				return (0);
			}
		}
		free(first_argument);
		free(line_no_space);
	}
	return (0);
}

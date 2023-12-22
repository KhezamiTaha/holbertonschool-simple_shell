#include "sh.h"
/**
 * main - The main function of the simple shell.
 *
 * Return: Always returns 0.
 *         Exits the program when the user enters "exit".
 */
int main(void)
{
	int n, counter = 0, flag = 0;
	char *lineptr, *first_argument, *line_no_space;

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
		line_no_space = handle_spaces(lineptr);
		if (line_no_space == NULL)
		{
			free(lineptr);
			continue;
		}
	}

	n = execute(line_no_space);
	if (n == -1)
	{
		flag = 1;
		free(first_argument);
		free(lineptr);
		return (0);
	}
	free(first_argument);
	free(line_no_space);

	return (0);
}

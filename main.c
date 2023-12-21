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
	int n, i, j, length;

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
			length = strlen(lineptr);

			for (i = 0; i < length && lineptr[i] == ' '; i++)
			{
			}

			if (lineptr[i] == '\0')
			{
				free (lineptr);
				continue;
			}
				

			for (j = 0; i < length; i++, j++)
			{
				lineptr[j] = lineptr[i];
			}

			lineptr[j] = '\0';
		}

		if (lineptr == NULL)
		{
			printf("===========");
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
			return (1);
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

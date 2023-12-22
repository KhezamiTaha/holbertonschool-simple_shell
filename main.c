#include "sh.h"
/**
 * main - The main function of the simple shell.
 *
 * Return: Always returns 0.
 *         Exits the program when the user enters "exit".
 */
int main(int argc, char *argv[])
{
	
	char *lineptr;
	int n, i, j, length, counter = 0;
	(void) argc;
	(void) argv;
	


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
				printf("%s: %d: %s: not found", argv[0], counter, linep)
				free(lineptr);
				return (0);
			}
			/*else if (n == -2)*/
		}

		free(lineptr);
	}
	return (0);
}

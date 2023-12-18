#include "sh.h"

int main(void)
{
	char *lineptr;
	while (1)
	{
		printf("$ ");
		fflush(stdout);

		lineptr = my_getline();

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
			execute(lineptr, environ);
		}

		free(lineptr);
	}

	return (0);
}

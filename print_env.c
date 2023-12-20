#include "sh.h"
/**
 * print_env - Prints the current environment variables.
 * : The environment variable array.
 *
 * Return: No return value.
 */
void print_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
	{
		printf("%s\n", environ[index]);
	}
}

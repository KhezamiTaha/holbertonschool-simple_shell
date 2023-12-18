#include "sh.h"

void print_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
	{
		printf("%s\n", environ[index]);
	}
}

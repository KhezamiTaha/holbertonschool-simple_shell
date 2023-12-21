#include "sh.h"
int freeArray(char** array)
{
	int i = 0;

	while(array[i] != NULL)
	{
		free(array[i++]);
	}
	free(array);
	return (0);
}

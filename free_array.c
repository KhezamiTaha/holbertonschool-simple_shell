#include "sh.h"
/**
 * freeArray - Frees the memory allocated
 * for a dynamically allocated array of strings.
 * @array: The array of strings to be freed.
 * @return Returns 0 upon successful freeing of memory.
 */
int freeArray(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i++]);
	}
	free(array);
	return (0);
}

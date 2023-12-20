#include "sh.h"
/**
 * my_getline - Reads a line of input from the standard input.
 *
 * Return: A dynamically allocated string containing the entered line.
 *         Exits the program with an error message if getline fails.
 */
char *my_getline(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    nread = getline(&line, &len, stdin);
    if (nread == -1)
    {
        free(line);
        return(NULL);
    }
    if (nread > 0 && line[nread - 1] == '\n')
    {
        line[nread - 1] = '\0';
    }
    return (line);
}

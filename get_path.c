#include "sh.h"

char *find_path(char *command)
{
    char *path_copy, *token, *path_env;
    struct stat st;

    path_env = getenv("PATH");
    if (path_env == NULL)
    {
        perror("PATH");
        exit(EXIT_FAILURE);
    }
    path_copy = strdup(path_env);
    if (path_copy == NULL)
    {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }
    token = strtok(path_copy, ":");
    while (token)
    {
        char full_path[1024];

        sprintf(full_path, "%s/%s", token, command);

        if (stat(full_path, &st) == 0)
        {
            command = full_path;

            return (command);
        }

        token = strtok(NULL, ":");
        if (token == NULL)
            printf("%s not found in PATH\n", command);
    }

    return (NULL);
}
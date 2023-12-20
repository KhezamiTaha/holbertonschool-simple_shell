#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int path(int argc, char *argv[])
{
	int i;
	char *path_copy, *token, *path_env;
	struct stat st;
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return EXIT_FAILURE;
	}

	for (i = 1; i < argc; i++)
	{
		path_env = getenv("PATH");

		if (path_env == NULL)
		{
			fprintf(stderr, "Error: PATH environment variable not set\n");
			exit(EXIT_FAILURE);
		}
		path_copy = strdup(path_env);

		if (path_copy == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		token = strtok(path_copy, ":");

		while (token != NULL)
		{
			char full_path[1024];

			snprintf(full_path, sizeof(full_path), "%s/%s", token, argv[i]);

			if (stat(full_path, &st) == 0)
			{
				printf("%s\n", full_path);
				break;
			}

			token = strtok(NULL, ":");
			if (token == NULL)
				printf("%s not found in PATH\n", argv[i]);
		}
	}

	return EXIT_SUCCESS;
}

int shell(void)
{
	int pid, status;
	char *lineptr = NULL;
	size_t n;
	char *argv[2];
	char *env[] = {NULL};

	printf("Simple Shell# ");
	fflush(stdout);
	pid = fork();
	if (pid == 0)
	{
		getline(&lineptr, &n, stdin);
		lineptr[strlen(lineptr) - 1] = '\0';
		argv[0] = lineptr;
		argv[1] = NULL;
		execve(lineptr, argv, env);
	}
	else
	{
		wait(&status);
	}

	return (0);
}
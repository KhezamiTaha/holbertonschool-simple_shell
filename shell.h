#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
char *_getline(void);
char **split_command(char *lineptr);
int execute(char **complet_command, char *env[]);

#endif
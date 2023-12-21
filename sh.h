#ifndef SH_H
#define SH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

char *my_getline(void);
int execute(char *command);
void print_env(void);
void exit_shell(void);
char *find_path(char *command);
int freeArray(char** array);

#endif

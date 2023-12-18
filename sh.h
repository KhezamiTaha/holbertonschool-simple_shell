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

extern char **environ;

char *my_getline(void);
void execute(char *command, char *env[]);
void print_env(char *env[]);
void exit_shell(void);

#endif

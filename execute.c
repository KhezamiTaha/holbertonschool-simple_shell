#include "sh.h"

void execute(char *command, char *env[]) {
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        char *argv[] = {command, NULL}; 
        execve(command, argv, env);

    } else {
        wait(&status);
    }
}

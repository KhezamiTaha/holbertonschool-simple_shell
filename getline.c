#include "sh.h"

char *my_getline(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread; 
    
    nread = getline(&line, &len, stdin);

    if (nread == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }

    if (nread > 0 && line[nread - 1] == '\n') {
        line[nread - 1] = '\0';
    }

    return (line);
}

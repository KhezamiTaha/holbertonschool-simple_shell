#include "sh.h"

int main(void) {
    char *lineptr;
    while (1) {
        printf("$ ");
        fflush(stdout);

        lineptr = my_getline();
        execute(lineptr, environ);
        free(lineptr);
    }

    return 0;
}

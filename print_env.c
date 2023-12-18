#include "sh.h"

void print_env(char *env[]) {
    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
}

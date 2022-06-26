#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    char *arguments[] = {"Hello", NULL};
    execv("./test", arguments);
}
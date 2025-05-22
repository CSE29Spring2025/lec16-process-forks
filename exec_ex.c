#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-lt", NULL};
    printf("About to exec ls -l\n");
    execvp("ls", args);
    printf("This line will not execute if exec succeeds\n");
    return 0;
}

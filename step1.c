#include <stdio.h>
#include <unistd.h>

// We have an if else statement? Do we get 1 or 2 print statements?
// Why?
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child Process, PID = %d\n", getpid());
    } else {
        printf("Parent Process, PID = %d\n", getpid());
    }
    return 0;
}

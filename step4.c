#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int value = 10;
    printf("Main (PID %d): value = %d\n", getpid(), value);
    pid = fork();

    if (pid == 0) { // Child
        printf("CHILD (PID %d): value initially = %d\n", getpid(), value);
        value = 20; // Child changes ITS copy
        printf("CHILD (PID %d): value now = %d\n", getpid(), value);
    } else if (pid > 0) { // Parent
        sleep(1); // Try to let child run first
        printf("PARENT (PID %d): Child PID %d\n", getpid(), pid);
        printf("PARENT (PID %d): value = %d (should be ?)\n", getpid(), value);
    }
    return 0;
}

#include <stdio.h>      // For printf
#include <unistd.h>     // For fork(), execvp()
#include <sys/types.h>  // For pid_t
#include <sys/wait.h>   // For wait()

int main() {
    pid_t pid = fork();
    
    if (pid == 0) { //check for child
        // CHILD
        char *args[] = {"ls", NULL};
        printf("Child PID %d\n", getpid());
        execvp("ls", args);
        // If execvp fails
        perror("execvp failed");
    } else if (pid > 0) {
        // PARENT
        wait(NULL); // Wait for child to finish
        printf("I am the parent %d\n", getpid());
    } else {
        perror("fork failed");
    }

    return 0;
}

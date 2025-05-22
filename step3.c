#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid_val;
    printf("MAIN: My PID is %d\n", getpid());
    pid_val = fork();

    if (pid_val < 0) { /* Error */
        fprintf(stderr, "Fork Failed\n"); return 1;
    } else if (pid_val == 0) { /* Child */
        printf("CHILD: My PID is %d, My PPID is %d\n", getpid(), getppid());
        printf("CHILD: fork() returned %d\n", pid_val);
    } else { /* Parent */
        printf("PARENT: My PID is %d\n", getpid());
        printf("PARENT: fork() returned %d (Child's PID)\n", pid_val);
    }
    printf("BOTH: This line is executed by PID %d\n", getpid());
    return 0;
}

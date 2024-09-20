/*
Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    // wait() in the parent process
    printf("PID: %d\n", getpid());
    pid_t rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("in the child process, pid = %d\n", getpid());
    } else {
        pid_t wt = wait(NULL);
        printf("in the parent process, pid = %d\n", getpid());
        printf("wait() in the parent process returned: %d\n", wt);
    }

    return 0;

    // wait() in the parent() process returns the terminated child process' process id
    
}
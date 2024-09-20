/*
Now write a program that uses wait() to wait for the child process
to finish in the parent. What happens if you use wait() in the child?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    // wait() in the child process

    printf("PID: %d\n", getpid());
    pid_t rc_2 = fork();
    if (rc_2 < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc_2 == 0) {
        pid_t wit = wait(NULL);
        printf("in the child process, pid = %d\n", getpid());
        printf("wait() in the child process returned: %d\n", wit);
    } else {
        printf("in the parent process, pid = %d\n", getpid());
    }

    return 0;

    // wait() in the child() process returns -1 since a child process 
    // doesn't have a child as it is the child

}
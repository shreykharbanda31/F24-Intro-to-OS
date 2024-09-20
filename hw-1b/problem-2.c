/*
Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including (on Linux) execl(), execle(),
execlp(), execv(), execvp(), and execvpe(). Why do
you think there are so many variants of the same basic call? 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    pid_t rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0){
        printf("Child process (pid: %d)\n", getpid());
        char * args1[] = {"ls", NULL};
        char * args2[] = {"/bin/ls", NULL}; // need to specify full path for execv and execve
        char *env[] = {"HOME=/home/user", "PATH=/usr/bin", NULL};
        execvp(args1[0], args1);

        //execv(args2[0], args2);
        //execve(args2[0], args2, env); 
        //execvpe(args1[0], args1, env);  // execvpe() is not allowed on MacOS

        //execl("/bin/ls", "ls", NULL);
        //execle("/bin/ls", "ls", NULL, env );
        //execlp("ls", "ls", NULL);
    } 
       
    else {
        wait(NULL);
        printf("Parent process (pid: %d)\n", getpid());
    }

    return 0;

    // execv()/execl()/execle()/execve(): These require the full path to the executable (e.g., /bin/ls).
    /* execvp()/execlp()/execvpe(): These variants automatically search for the executable in the directories 
       listed in the PATH environment variable, so we can just specify the command without the full path. */
    /* The choice between execl() and execv() type variants depends on how the arguments are available or structured in the program. 
       Using an array (execv()) may be easier when arguments are dynamic or need to be passed programmatically. */
    // The execvpe()/execle() variant allows us to specify a different environment for the executed program.
    /* These environmental variants allow control over the environment of the new process, which is useful in cases 
        where we want to manipulate or isolate the environment from the parent process. */
    /*
    Overall, These different variants exist to support passing arguments either individually or in an array, 
    to let the system search for the executable in the PATH or to manually specify the full path, 
    and/or to allow control over environment variables in the new process.
    */
    
}


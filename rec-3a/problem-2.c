#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    int x = 100;
    printf("Original x = %d\n", x);
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if(rc == 0){
        printf("Child: x = %d\n", x);
        x = 50;
        printf("Child: x = %d\n", x);
    } else {
        wait(1);
        printf("Parent: x = %d\n", x);
        x = 70;
        printf("Parent: x = %d\n", x);
    }
    printf("Overall x = %d\n", x);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void * print1(void *arg){
    printf("%s\n", (char *) arg);
    return NULL;
}

int main(int argc, char *argv[]){
    if(argc != 1){
        fprintf(stderr, "usage: main\n");
        exit(1);
    }

    pthread_t p1, p2;
    printf("main: begin\n");
    pthread_create(&p1, NULL, print1, "First Thread");
    pthread_create(&p2, NULL, print1, "Second Thread");
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("main: end\n");
    return 0;
}
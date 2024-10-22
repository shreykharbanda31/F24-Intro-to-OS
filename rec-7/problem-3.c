#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct myarg_t {
    int a;
    int b;
};

void * mythread(void *arg){
    struct myarg_t *args = (struct myarg_t *) arg;
    printf("%d %d\n", args->a, args->b);
    return NULL;
}


int main(int argc, char *argv[]){
    if(argc != 1){
        fprintf(stderr, "usage: main\n");
        exit(1);
    }
    struct myarg_t args;
    args.a = 10;
    args.b = 20; 
    pthread_t p1;
    printf("main: begin\n");
    pthread_create(&p1, NULL, mythread, &args);
    pthread_join(p1, NULL);
    printf("main: end\n");
    return 0;
}
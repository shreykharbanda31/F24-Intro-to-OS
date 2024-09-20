#include <stdio.h>
#include <string.h>
#include <unistd.h> 

typedef enum {
    IDLE,
    RUNNING,
    FINISHED
} State;

void idleState();
void runningState();
void finishedState();

State currentState = IDLE;

int main() {
    char inp[10];

    idleState();

    while (currentState != FINISHED) {
        if (currentState == IDLE) {
            printf("Enter 'start' to begin: ");
            scanf("%s", inp);

            if (strcmp(inp, "start") == 0) {
                currentState = RUNNING;
                runningState();
            }
        } else if (currentState == RUNNING) {
            printf("Task is running...\n");
            sleep(10);
            currentState = FINISHED;
            finishedState();
        }
    }

    return 0;
}

void idleState() {
    printf("Program is in IDLE state.\n");
}

void runningState() {
    printf("Program is now RUNNING.\n");
}

void finishedState() {
    printf("Program has FINISHED.\n");
}

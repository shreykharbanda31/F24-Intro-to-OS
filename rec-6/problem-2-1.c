#include <stdio.h>
#include <stdlib.h>

int main(){
    int* num = malloc(sizeof(int));
    printf("Enter a number: ");
    scanf("%d", num);
    int* sum = malloc(sizeof(int));
    *sum = 0;
    for(int i = 1; i <= *num; i+=2){
        *sum += i;
    }
    printf("Sum: %d\n", *sum);
    free(sum);
    free(num);
    return 0;
}
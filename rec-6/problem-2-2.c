#include <stdio.h>
#include <stdlib.h>

int main(){

    size_t size = 5; 
    size_t length = 0;
    char *str = malloc(size * sizeof(char)+1);
    while (1){
        char ch;
        scanf("%c", &ch);
        if(ch == '\n'){
            break;
        }
        if (length +1 > size){
            
        }
        length++;

    }
    free(str);
    return 0;
}

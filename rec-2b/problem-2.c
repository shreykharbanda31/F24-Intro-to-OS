#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    char filename[256];
    FILE *file;

    printf("Enter the filename to open: ");
    fgets(filename, sizeof(filename), stdin);
    
    //remove newline character from filename if it exists
    filename[strcspn(filename, "\n")] = '\0';

    //try to open the file
    file = fopen(filename, "r");

    if (file == NULL) {
        switch (errno) {
            case ENOENT: //no such file or directory
                printf("Error: File not found. %s.\n", strerror(errno));
                break;
            case EACCES: //perm denied
                printf("Error: %s.\n", strerror(errno));
                break;
        }
    } else {
        printf("File opened successfully.\n");
        fclose(file);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main() {
    char filename[256];
    mode_t readOnlyPermissions = 0444; // user: read, group: read, others: read

    printf("Enter the filename to make read-only: ");
    scanf("%s", filename);

    if (chmod(filename, readOnlyPermissions) != 0) {
        printf("Error changing file permissions: %s\n", strerror(errno));
        exit(1);
    }

    printf("File '%s' has been successfully changed to read-only.\n", filename);

    return 0;
}

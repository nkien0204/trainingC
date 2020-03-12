#include<stdio.h>
#include<string.h>


int main() {
    FILE *fptr;
    char directory[100], target[10];

    do {
        printf("Enter directory of folder (with '/' on the end): ");
        scanf("%s", directory);
    } while (directory[strlen(directory) - 1] != '/');
    printf("Enter file or folder to search: ");
    scanf("%s", target);

    strcat(directory, target);
    
    fptr = fopen(directory, "r");
    if (fptr != NULL) {
        printf("Result: ");
        for (int i = strlen(directory) - 1; i >= 0; i--) {
        if (directory[i] == '/') {
            for (i = i + 1; i < strlen(directory); i++) {
                printf("%c", directory[i]);
            }
            break;
        }
    }
    } else {
        printf("File does not exist.\n");
    }
    printf("\n");
    return 0;
}
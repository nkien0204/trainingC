#include"proj.h"
#include<regex.h>

void Regex(char r_target[], char *fName);
void getFile();

int main() {
    getFile();
    return 0;
}

void Regex(char r_target[], char *fName) {
    regex_t regex;
    int reti;
    char reg_ex[10] = "";
    strcat(reg_ex, r_target);
    reti = regcomp(&regex, reg_ex, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }
    reti = regexec(&regex, fName, 0, NULL, 0);
    if (!reti) {
        printf("%s\n", fName);
    }
    regfree(&regex);
}

void getFile() {
    FILE *fptr = NULL;
    char line[255];
    char fileDirectory[100], target[10];
    printf("Directing to the file: ");
    scanf("%s", fileDirectory);
    fptr = fopen(fileDirectory, "r");
    if (fptr == NULL) {
        printf("Error on opening file\n");
        exit(1);
    }
    printf("String to search: ");
    scanf("%s", target);
    while (fgets(line, 255, fptr)) {
        fgets(line, 255, fptr);
        Regex(target, line);
    }
    fclose(fptr);
}
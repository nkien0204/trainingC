#include"proj.h"
#include<regex.h>
#include<dirent.h> 

void Find();
void Regex(char *r_target, char *fileName);

int main() {  
    Find();
    return 0;
}

void Find() {
    FILE *fptr;
    char directory[100], target[10];
    struct dirent *drent;

    printf("Enter directory of folder: ");
    scanf("%s", directory);
    
    printf("Enter file or folder to search: ");
    scanf("%s", target);

    //point dir to folder
    DIR *dir = opendir(directory);
    if (dir == NULL) { 
        printf("Could not open current directory" ); 
        return; 
    }
    printf("Result: \n");
    while ((drent = readdir(dir)) != NULL) {
        Regex(target, drent->d_name);
    }
    closedir(dir);
    printf("\n");
}

void Regex(char r_target[], char *fName) {
    regex_t regex;
    int reti;
    char reg_ex[10] = "^";
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
}
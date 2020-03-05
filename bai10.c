#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main() {
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    float **buff = (float **)malloc(N * sizeof(float *));
    for (int i = 0; i < N; i++) {
        buff[i] = (float *)malloc(sizeof(float));
    }
    
    FILE *fptr;
    char chBuff[255];
    fptr = fopen("/home/kn/vsCode/trainingC/bai10.txt", "r");
    fgets(chBuff, 255, fptr);
    for (int i = 0; i < N; i++) {
        fgets(chBuff, 255, fptr);
        printf("%s", chBuff);
    }


    return 0;
}

float strFloat(char *str) {
    float result;
    for (int i = 0; i < strlen(str); i++) {
        
    }
    return result;
}
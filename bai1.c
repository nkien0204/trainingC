#include<stdio.h>
#include<stdlib.h>

int main() {
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    int **array = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        array[i] = (int *)malloc(N * sizeof(int));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = (i + 1)*(j + 1);
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);
}
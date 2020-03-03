#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    FILE *ptr = NULL;
    int N, min, max;
    srand((int)time(0));
    printf("Enter N: ");
    scanf("%d", &N);
    int **matrix = (int **)malloc((N + 2) * sizeof(int *));
    for (int i = 0; i < N + 2; i++) {
        matrix[i] = (int *)malloc(N * sizeof(int));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    ptr = fopen("/home/kn/Desktop/bai4.txt", "w");
    if (ptr == NULL) {
        printf("ERROR\n");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        min = matrix[0][i];
        max = matrix[0][i];
        for (int j = 0; j < N; j++) {
            if (min > matrix[j][i]) {
                min = matrix[j][i];
            }
            if (max < matrix[j][i]) {
                max = matrix[j][i];
            }
        }
        matrix[N][i] = min;
        matrix[N + 1][i] = max;
    }

    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(ptr, "%d ", matrix[i][j]);
        }
        fprintf(ptr, "%s","\n");
    }

    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
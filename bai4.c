#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int **inputMatrix(int **matrix, unsigned int row, unsigned int column);
FILE *exportFile(FILE *ptr, char *destination, char *mode, int **content, unsigned int row, unsigned int column);
int **maxMin(int **matrixNew, int **matrix, unsigned int N);

int main(){
    FILE *ptr = NULL;
    int **matrix = NULL, **matrixNew = NULL;
    int N;
    srand((int)time(0));
    printf("Enter N: ");
    scanf("%d", &N);
    matrix = inputMatrix(matrix, N, N);
    matrixNew = inputMatrix(matrix, N + 2, N);

    ptr = exportFile(ptr, "/home/kn/vsCode/trainingC/bai4.txt", "w", matrix, N, N);

    ptr = fopen("/home/kn/vsCode/trainingC/bai4.txt", "a");
    fprintf(ptr, "%s", "\n\n");
    fclose(ptr);

    matrixNew = maxMin(matrixNew, matrix, N);
    
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    ptr = exportFile(ptr, "/home/kn/vsCode/trainingC/bai4.txt", "a", matrixNew, N + 2, N);

    for (int i = 0; i < N + 2; i++) {
        free(matrixNew[i]);
    }
    free(matrixNew);

    return 0;
}

int **inputMatrix(int **matrix, unsigned int row, unsigned int column) {
    matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int *)malloc(column * sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

FILE *exportFile(FILE *ptr, char *destination, char *mode, int **content, unsigned int row, unsigned int column) {
    ptr = fopen(destination, mode);

    if (ptr == NULL) {
        printf("ERROR\n");
        exit(1);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            fprintf(ptr, "%d ", content[i][j]);
        }
        fprintf(ptr, "%s","\n");
    }

    fclose(ptr);

    return ptr;
}

int **maxMin(int **matrixNew, int **matrix, unsigned int N) {
    int min, max;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrixNew[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        min = matrixNew[0][i];
        max = matrixNew[0][i];
        for (int j = 0; j < N; j++) {
            if (min > matrixNew[j][i]) {
                min = matrixNew[j][i];
            }
            if (max < matrixNew[j][i]) {
                max = matrixNew[j][i];
            }
        }
        matrixNew[N][i] = min;
        matrixNew[N + 1][i] = max;
    }

    return matrixNew;
}
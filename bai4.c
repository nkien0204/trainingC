#include"proj.h"

void bai4(){
    FILE *fptr = NULL;
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    int **matrix;

    
    inputMatrix(&matrix, N);

    exportFile(&fptr, "/home/kn/vsCodeWS/trainingC/bai4.txt", "w", matrix, N, N);

    fptr = fopen("/home/kn/vsCodeWS/trainingC/bai4.txt", "a");
    fprintf(fptr, "%s", "\n\n");
    fclose(fptr);

    matrix = (int **)realloc(matrix, (N + 2) * sizeof(int*));
    for (int i = 0; i < N + 2; i++) {
        matrix[i] = (int *)realloc(matrix[i], N * sizeof(int));
    }

    maxMin(&matrix, N);

    exportFile(&fptr, "/home/kn/vsCodeWS/trainingC/bai4.txt", "a", matrix, N + 2, N);

    for (int i = 0; i < N + 2; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void inputMatrix(int ***matrix, unsigned int N) {
    *matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        (*matrix)[i] = (int *)malloc(N * sizeof(int));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            (*matrix)[i][j] = rand() % 10;
        }
    }
}

void exportFile(FILE **ptr, char *destination, char *mode, int **content, unsigned int row, unsigned int column) {
    *ptr = fopen(destination, mode);

    if (*ptr == NULL) {
        printf("ERROR\n");
        exit(1);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            fprintf(*ptr, "%d ", content[i][j]);
        }
        fprintf(*ptr, "%s","\n");
    }

    fclose(*ptr);
}

void maxMin(int ***matrixNew, unsigned int N) {
    int min, max;
    for (int i = 0; i < N; i++) {
        min = (*matrixNew)[0][i];
        max = (*matrixNew)[0][i];
        for (int j = 0; j < N; j++) {
            if (min > (*matrixNew)[j][i]) {
                min = (*matrixNew)[j][i];
            }
            if (max < (*matrixNew)[j][i]) {
                max = (*matrixNew)[j][i];
            }
        }
        (*matrixNew)[N][i] = min;
        (*matrixNew)[N + 1][i] = max;
    }
}
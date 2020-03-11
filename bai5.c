#include"proj.h"

void bai5() {
    unsigned int size;
    printf("Enter size: ");
    scanf("%d", &size);

    double **matrix1 = (double **)malloc(size * sizeof(double *));
    double **matrix2 = (double **)malloc(size * sizeof(double *));
    double **addMatrix = (double **)malloc(size * sizeof(double *));
    double **multMatrix = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        matrix1[i] = (double *)malloc(size * sizeof(double));
        matrix2[i] = (double *)malloc(size * sizeof(double));
        addMatrix[i] = (double *)malloc(size * sizeof(double));
        multMatrix[i] = (double *)malloc(size * sizeof(double));
    }

    input(&matrix1, size);
    input(&matrix2, size);
    print(matrix1, size);
    printf("\n");
    print(matrix2, size);

    printf("\nMatrix1 + Matrix2: \n");
    add(matrix1, matrix2, &addMatrix, size);
    print(addMatrix, size);
    printf("\n");
    printf("Matrix1 * Matrix2: \n");
    mult(matrix1, matrix2, &multMatrix, size);
    print(multMatrix, size);
    printf("\n");

    for(int i = 0; i < size; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(addMatrix[i]);
        free(multMatrix[i]);
    }
    free(matrix1);
    free(matrix2);
    free(addMatrix);
    free(multMatrix);
}

void input(double ***matrix, unsigned int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            (*matrix)[i][j] = rand() % 10;
        }
    }
}

void print(double **matrix, unsigned size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void mult(double **matrix1, double **matrix2, double ***output, unsigned size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            (*output)[i][j] = 0;
        }
    }

    for (int z = 0; z < size; z++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                (*output)[i][z] = (*output)[i][z] + matrix1[i][j] * matrix2[j][z];
            }
        }
    }
}

void add(double **matrix1, double **matrix2, double ***output, unsigned size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            (*output)[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
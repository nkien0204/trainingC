#include"bai5.h"

int main() {
    unsigned int size;
    printf("Enter size: ");
    scanf("%d", &size);
    double **matrix;
    input(matrix, size);

    for(int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void input(double **matrix, unsigned size) {
    srand((int)time(0));
    matrix = (double **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double *)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    print(matrix, size);
}

void print(double **matrix, unsigned size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void mult(const double *matrix1, const double *matrix2, double **output, unsigned size) {

}
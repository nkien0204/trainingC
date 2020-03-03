#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void input(double **matrix, unsigned size);
void print(double **matrix, unsigned size);
void mult(const double *matrix1, const double *matrix2, double **output, unsigned size);
void add(const double *matrix1, const double *matrix2, double **output, unsigned size);
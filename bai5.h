#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double **input(double **matrix, unsigned size);
void print(double **matrix, unsigned size);
double **mult(double **matrix1, double **matrix2, double **output, unsigned size);
double **add(double **matrix1, double **matrix2, double **output, unsigned size);
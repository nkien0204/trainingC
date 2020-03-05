#include<stdio.h>
#include<stdlib.h>

int **as(int **a, int N) {
    a = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        a[i] = (int *)malloc(N * sizeof(int));
    }
}

int main() {
    int **a;
    a = as(a, 3);
    return 0;
}
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(){
    int decima = 55;
    int re, capacity = 0, i = 1;
    int *array;
    if (decima <= 255) {
        array = (int *)malloc(8 * sizeof(int));
        capacity = 8;
    } else if (decima > 255 && decima < pow(2, 16) ) {
        array = (int *)malloc(16 * sizeof(int));
        capacity = 16;
    } else if (decima > pow(2, 16) && decima < pow(2,32) ) {
        array = (int *)malloc(32 * sizeof(int));
        capacity = 32;
    }

    do {
        re = decima % 2;
        decima = decima / 2;
        array[capacity - i] = re;
        i++;
    }while(decima > 0);
    for(int i = 0; i < capacity; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
    free(array);
}
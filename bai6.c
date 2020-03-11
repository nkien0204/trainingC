#include"proj.h"

void bai6() {
    int num;
    printf("Enter number of people: ");
    scanf("%d", &num);
    writeNames(num);
}
void readNames(char *names[], const int size) {
    for (int i = 0; i < size; i++) {
        printf("%s ", names[i]);
    }
    printf("\n");
}

void writeNames(const int size) {
    char **names;
    names = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        names[i] = (char *)malloc(size * sizeof(char));
    }
    for (int i = 0; i < size; i++) {
        printf("Enter name: ");
        scanf("%s", names[i]);
    }
    bubbleSort(names, size);
    readNames(names, size);
    for (int i = 0; i < size; i++) {
        free(names[i]);
    }
    free(names);
}

void bubbleSort(char *names[], const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                swap(&names[j], &names[j + 1]);
            }
        }
    }
}

void swap(char **name1, char **name2) {
    char *temp;
    temp = *name1;
    *name1 = *name2;
    *name2 = temp;
}


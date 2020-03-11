#include"proj.h"

void bai8() {
    node head = NULL;
    int size = 5;
    int array[size];
    printf("Enter element of array:\n");
    for (int i = 0; i < size; i++) {
        printf("Array[%d] = ", i);
        scanf("%d", &array[i]);
    }
    printf("\nConvert to Linked list: ");
    head = convert(head, array, size);
    display8(head);

    for (node ptr = head; ptr != NULL; ptr = ptr->next) {
        free(ptr);
    }
}

node createNode8() {
    node temp = (node)malloc(sizeof(struct Node));
    temp->next = NULL;
    return temp;
}

node pushBack8(node head, int data) {
    node ptr, temp = createNode8();
    if (head == NULL) {
        head = temp;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;      
    }
    temp->data = data;
    return head;
}

node convert(node head, int *array, int size) {
    node ptr = head;
    for (int i = 0; i < size; i++) {
        head = pushBack8(head, array[i]);
    }
    return head;
}

void display8(node head) {
    node ptr = head;
    for (ptr; ptr != NULL; ptr = ptr->next) {
        printf("%d ", (ptr->data));
    }
    printf("\n");
}
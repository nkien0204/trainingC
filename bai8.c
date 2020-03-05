#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
    int data;
    struct Node *next;
} *node;

node createNode();
node pushBack(node head, int data);
node convert(node head, int *array, int size);
void display(node head);

int main() {
    node head = NULL;
    srand((int)time(0));
    int size = 5;
    int array[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10;
        printf("%d ", array[i]);
    }
    printf("\n");
    head = convert(head, array, size);
    display(head);

    for (node ptr = head; ptr != NULL; ptr = ptr->next) {
        free(ptr);
    }

    return 0;
}

node createNode() {
    node temp = (node)malloc(sizeof(struct Node));
    temp->next = NULL;
    return temp;
}

node pushBack(node head, int data) {
    node ptr, temp = createNode();
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
        head = pushBack(head, array[i]);
    }
    return head;
}

void display(node head) {
    node ptr = head;
    for (ptr; ptr != NULL; ptr = ptr->next) {
        printf("%d ", (ptr->data));
    }
    printf("\n");
}
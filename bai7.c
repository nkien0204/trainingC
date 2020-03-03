#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void addNode(struct Node *head, int data, unsigned int size) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    temp->data = data;
    for (int i = 0; i < size; i++) {
        ptr->next = temp;
        ptr = ptr->next;
    }
    display(head, size);
}

void display(struct Node *head, unsigned int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", (head->data));
        head = head->next;
    }
}

int main(){
    srand((int)time(0));
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    addNode(head, 120, 5);
    return 0;
}
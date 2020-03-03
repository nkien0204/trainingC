#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *addFirst() {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = rand() % 10;
    temp->next = head;
    head = temp;
    return head;
}

void display(struct Node *head, unsigned int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", (head->data));
        head = head->next;
    }
    printf("\n");
}

void insert(struct Node *head, unsigned int size) {
    struct Node *ptr = head;
    for (int i = 0; i < size; i++) {
        if ((ptr->data) % 2 != 0) {
            
        }
    }
}

int main(){
    unsigned int size;
    srand((int)time(0));
    printf("Enter size: ");
    scanf("%d", &size);
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    for(int i = 0; i < size; i++) {
        head = addFirst();
    }
    display(head, size);
    return 0;
}
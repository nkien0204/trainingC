#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} *node;

node createNode(int data);
node pushBack(node head, int data);

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    return 0;
}

node createNode(int data) {
    node temp = (node)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

node pushBack(node head, int data) {
    node ptr, temp = createNode(data);
    if (head == NULL) {
        head = temp;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}
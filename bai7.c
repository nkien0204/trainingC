#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *node;

node head = NULL;

node createNode() {
    node temp = (node)malloc(sizeof(struct Node));
    temp->data = rand() % 100;
    temp->next = NULL;
    return temp;
}

node pushBack(node head) {
    node temp, ptr;
    temp = createNode();
    if (head == NULL) {
        head = temp;
    } else {
        node ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}

node addPosition(node head, unsigned int position) {
    node ptr = head;
    node temp = createNode();
    if (position == 0) {
        temp->next = head;
        head = temp;
    } else {
        int i = 0;
        while (ptr != NULL) {
            if (i == position - 1) {
                temp->next = ptr->next;
                ptr->next = temp;
            }
            ptr = ptr->next;
            i++;
        }
    }
    return head;
}

node mission(node head) {
    node ptr = head;
    node temp;
    int i = 0;
    while (ptr != NULL) {
        if ((ptr->data) % 2 != 0) {
            addPosition(head, i + 1);
            temp->data = (ptr->data) * (ptr->data);
            printf("temp data: %d ", temp->data);
            ptr = ptr->next;
        }
        i++;
        ptr = ptr->next;
    }
    printf("\n");
    return head;
}

void display(node head) {
    node ptr = head;
    for (ptr; ptr != NULL; ptr = ptr->next) {
        printf("%d ", (ptr->data));
    }
    printf("\n");
}

int main() {
    unsigned int size;
    srand((int)time(0));
    printf("Enter size: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        head = pushBack(head);
    }
    display(head);
    head = mission(head);
    //addPosition(head, 5);
    display(head);
    free(head);
    return 0;
}
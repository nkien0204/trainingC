#include"proj.h"

node createNode7() {
    node temp = (node)malloc(sizeof(struct Node));
    temp->data = rand() % 100;
    temp->next = NULL;
    return temp;
}

node pushBack7(node head) {
    node temp, ptr;
    temp = createNode7();
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

node addPosition(node head, unsigned int position) {
    node ptr = head;
    node temp = createNode7();
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
    for (ptr; ptr != NULL; ptr = ptr->next) {
        if (ptr->data % 2 != 0) {
            addPosition(head, i + 1);
            ptr->next->data = (ptr->data) * (ptr->data);
            ptr = ptr->next;
            i++;
        }
        i++;
    }
    return head;
}

void display7(node head) {
    node ptr = head;
    for (ptr; ptr != NULL; ptr = ptr->next) {
        printf("%d ", (ptr->data));
    }
    printf("\n");
}

void bai7() {
    node head = NULL;
    unsigned int size;
    printf("Enter size: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        head = pushBack7(head);
    }
    display7(head);
    mission(head);
    display7(head);
    for (node ptr = head; ptr != NULL; ptr = ptr->next) {
        free(ptr);
    }
}
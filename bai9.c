#include"proj.h"

void bai9() {
    unsigned int n;
    double x;
    node head = NULL;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("\nEnter x: ");
    scanf("%lf", &x);
    
    for (int i = 0; i < n + 1; i++) {
        head = pushBack(head, rand() % 10);
    }   
    display9(head, x);
    free(head);
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

void display9(node head, double x) {
    int i = 1;
    for (node ptr = head; ptr != NULL; ptr = ptr->next) {
        if (ptr == head) {
            if (ptr->next != NULL) {
                printf("%d + ", ptr->data);
            } else {
                printf("%d", ptr->data);
            }
        } else if (ptr->next != NULL) {
            printf("%dx^%d + ", ptr->data, i);
            i++;
        } else {
            printf("%dx^%d", ptr->data, i);
        }
    }
    printf(" = %f\n", calculate(head, x));
}

double calculate(node head, double x) {
    node ptr = head;
    double result = 0;
    double i = 0;
    for (ptr; ptr != NULL; ptr = ptr->next) {
        result += (ptr->data) * pow(x, i);
        i++; 
    }
    return result;
}
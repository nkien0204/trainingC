#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct Node {
    float data;
    struct Node *next, *left, *right;
} *node;

node createNode(float data);
void pushBack(node *head, float data);
void strFloat(float *result, const char *str);
void display(node d_head);
void insertBST(node *root, float data);
bool leftOf(node l_root, float l_data);
bool rightOf(node r_root, float r_data);
void preOrder(node p_root);
void inOrder(node i_root);
void postOrder(node p_root);
bool search(node s_root, float value);
float leftMostNode(node l_root);
void delete(node *d_root, float value);
void Free(node root)
{
    if (root == NULL )
        return;
    else {
        Free(root->left );
        Free(root->right );
        free(root );
    }
}

int main() {
    int N;
    char *endPoint;
    node head = NULL;
    node root = NULL;
    printf("Enter N: ");
    scanf("%d", &N);
    float *buff = (float *)malloc(N * sizeof(float));
    FILE *fptr;
    char chBuff[255];
    fptr = fopen("/home/kn/vsCodeWS/trainingC/bai10.txt", "r");
    fgets(chBuff, 255, fptr);
    for (int i = 0; i < N; i++) {
        fgets(chBuff, 255, fptr);
        printf("%s", chBuff);
        pushBack(&head, strtof(chBuff, &endPoint));
    }
    display(head);
    for (node ptr = head; ptr != NULL; ptr = ptr->next) {
        insertBST(&root, (ptr->data));
    }
    printf("\nPreOrder: ");
    preOrder(root);
    printf("\nInOrder: ");
    inOrder(root);
    printf("\nPostOrder: ");
    postOrder(root);
    printf("\n\n");
    delete(&root, 7);
    preOrder(root);
    printf("\n");
    Free(root);
    free(head);
    return 0;
}

node createNode(float data) {
    node temp = (node)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

void pushBack(node *head, float data) {
    node ptr, temp = createNode(data);
    if (*head == NULL) {
        *head = temp;
    } else {
        ptr = *head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display(node d_head) {
    printf("Linked list: ");
    node ptr = d_head;
    for (ptr; ptr != NULL; ptr = ptr->next) {
        printf("%.4f ", ptr->data);
    }
    printf("\n");
}

void insertBST(node *head, float i_data) {
    if (*head == NULL) {
        node temp = (node)malloc(sizeof(struct Node));
        (temp)->data = i_data;
        (temp)->left = NULL;
        (temp)->right = NULL;
        *head = temp;
    } else if (leftOf(*head, i_data)) {
        insertBST(&((*head)->left), i_data);
    } else if (rightOf(*head, i_data)) {
        insertBST(&((*head)->right), i_data);
    }
}

bool leftOf(node l_root, float l_data) {
    return l_data < (l_root->data);
}

bool rightOf(node r_root, float r_data) {
    return r_data > (r_root->data);
}

void preOrder(node p_root) {
    if (p_root != NULL) {
        printf("%.4f ", p_root->data);
        preOrder(p_root->left);
        preOrder(p_root->right);
    }
}

void inOrder(node p_root) {
    if (p_root != NULL) {
        inOrder(p_root->left);
        printf("%.4f ", p_root->data);
        inOrder(p_root->right);
    }
}

void postOrder(node p_root) {
    if (p_root != NULL) {
        postOrder(p_root->left);
        postOrder(p_root->right);
        printf("%.4f ", p_root->data);
    }
}

bool search(node s_root, float value) {
    if (s_root == NULL) {
        return false;
    } else if (s_root->data == value) {
        return true;
    } else if (leftOf(s_root, value)) {
        search(s_root->left, value);
    } else {
        search(s_root->right, value);
    }
}

float leftMostNode(node l_root) {
    node ptr;
    for (ptr = l_root; ptr->next != NULL; ptr = ptr->left);
    return ptr->data;
}

void delete(node *d_root, float value) {
    if (*d_root == NULL) {
        printf("NULL\n");
    } else if (leftOf(*d_root, value)) {
        delete(&((*d_root)->left), value);
    } else if (rightOf(*d_root, value)) {
        delete(&((*d_root)->right), value);
    } else {
        if ((*d_root)->left == NULL) {
            node newNode = (*d_root)->right;
            free(*d_root);
            *d_root = newNode;
            return;
        }
        if ((*d_root)->right == NULL) {
            node newNode = (*d_root)->right;
            free(*d_root);
            *d_root = newNode;
            return;
        }
        (*d_root)->data = leftMostNode((*d_root)->right);

        delete(&((*d_root)->right), ((*d_root)->data));
    }
}
#include"proj.h"

void bai10() {
    int N;
    char *endPoint;
    node10 head = NULL;
    node10 root = NULL;
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
        pushBack10(&head, strtof(chBuff, &endPoint));
    }
    display10(head);
    for (node10 ptr = head; ptr != NULL; ptr = ptr->next) {
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
}

node10 createNode10(float data) {
    node10 temp = (node10)malloc(sizeof(struct Node10));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

void pushBack10(node10 *head, float data) {
    node10 ptr, temp = createNode10(data);
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

void display10(node10 d_head) {
    printf("Linked list: ");
    node10 ptr = d_head;
    for (ptr; ptr != NULL; ptr = ptr->next) {
        printf("%.4f ", ptr->data);
    }
    printf("\n");
}

void insertBST(node10 *head, float i_data) {
    if (*head == NULL) {
        node10 temp = (node10)malloc(sizeof(struct Node10));
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

bool leftOf(node10 l_root, float l_data) {
    return l_data < (l_root->data);
}

bool rightOf(node10 r_root, float r_data) {
    return r_data > (r_root->data);
}

void preOrder(node10 p_root) {
    if (p_root != NULL) {
        printf("%.4f ", p_root->data);
        preOrder(p_root->left);
        preOrder(p_root->right);
    }
}

void inOrder(node10 p_root) {
    if (p_root != NULL) {
        inOrder(p_root->left);
        printf("%.4f ", p_root->data);
        inOrder(p_root->right);
    }
}

void postOrder(node10 p_root) {
    if (p_root != NULL) {
        postOrder(p_root->left);
        postOrder(p_root->right);
        printf("%.4f ", p_root->data);
    }
}

bool search(node10 s_root, float value) {
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

float leftMostNode(node10 l_root) {
    node10 ptr;
    for (ptr = l_root; ptr->next != NULL; ptr = ptr->left);
    return ptr->data;
}

void delete(node10 *d_root, float value) {
    if (*d_root == NULL) {
        printf("NULL\n");
    } else if (leftOf(*d_root, value)) {
        delete(&((*d_root)->left), value);
    } else if (rightOf(*d_root, value)) {
        delete(&((*d_root)->right), value);
    } else {
        if ((*d_root)->left == NULL) {
            node10 newNode = (*d_root)->right;
            free(*d_root);
            *d_root = newNode;
            return;
        }
        if ((*d_root)->right == NULL) {
            node10 newNode = (*d_root)->right;
            free(*d_root);
            *d_root = newNode;
            return;
        }
        (*d_root)->data = leftMostNode((*d_root)->right);

        delete(&((*d_root)->right), ((*d_root)->data));
    }
}

void Free(node10 root) {
    if (root == NULL )
        return;
    else {
        Free(root->left);
        Free(root->right);
        free(root);
    }
}
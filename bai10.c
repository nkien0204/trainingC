#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct Node {
    float data;
    struct Node *next;
} *node;

node createNode(float data);
node pushBack(node head, float data);
float strFloat(const char *str);

int main() {
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    float *buff = (float *)malloc(N * sizeof(float ));
    
    FILE *fptr;
    char chBuff[255];
    fptr = fopen("/home/kn/vsCode/trainingC/bai10.txt", "r");
    fgets(chBuff, 255, fptr);
    for (int i = 0; i < N; i++) {
        fgets(chBuff, 255, fptr);
        printf("%s", chBuff);
        buff[i] = strFloat(chBuff);
        printf("%f ", buff[i]);
    }

    return 0;
}

float strFloat(const char *str) {
    float result, result1, result2;
    char *s1, *s2;
    int i = 0, expLen = 0;
    while (i < strlen(str)) {
        s1 = strcat(s1, str[i]);
        result1 = atoi(s1);
        i++;
        if (str[i] == '.') {
            expLen = strlen(str) - i - 1;
            while (++i < strlen(str)) {
                s2 = strcat(s2, str[i]);
                result2 = atoi(s2);
            }    
        }
    }
    return result1 + result2 / pow(10, expLen);
}

node createNode(float data) {
    node temp = (node)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

node pushBack(node head, float data) {
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
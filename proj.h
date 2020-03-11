#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

typedef struct Node10 {
    float data;
    struct Node10 *next, *left, *right;
} *node10;

typedef struct Node {
    int data;
    struct Node *next;
} *node;

//bai1
void bai1();

//bai3
void bai3();

//bai4
void inputMatrix(int ***matrix, unsigned int N);
void exportFile(FILE **ptr, char *destination, char *mode, int **content, unsigned int row, unsigned int column);
void maxMin(int ***matrixNew, unsigned int N);
void bai4();

//bai5
void input(double ***matrix, unsigned size);
void print(double **matrix, unsigned size);
void mult(double **matrix1, double **matrix2, double ***output, unsigned size);
void add(double **matrix1, double **matrix2, double ***output, unsigned size);
void bai5();

//bai6
void readNames(char *names[], const int size);
void writeNames(const int size);
void bubbleSort(char *names[], const int size);
void swap(char **name1, char **name2);
void bai6();

//bai7
node createNode7();
node pushBack7(node head);
node addPosition(node head, unsigned int position);
node mission(node head);
void display7(node head);
void bai7();

//bai8
node createNode8();
node pushBack8(node head, int data);
node convert(node head, int *array, int size);
void display8(node head);
void bai8();

//bai9
node createNode(int data);
node pushBack(node head, int data);
void display9(node head, double x);
double calculate(node head, double x);
void bai9();

//bai10
node10 createNode10(float data);
void pushBack10(node10 *head, float data);
void strFloat(float *result, const char *str);
void display10(node10 d_head);
void insertBST(node10 *root, float data);
bool leftOf(node10 l_root, float l_data);
bool rightOf(node10 r_root, float r_data);
void preOrder(node10 p_root);
void inOrder(node10 i_root);
void postOrder(node10 p_root);
bool search(node10 s_root, float value);
float leftMostNode(node10 l_root);
void delete(node10 *d_root, float value);
void Free(node10 root);
void bai10();
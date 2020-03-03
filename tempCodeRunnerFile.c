void addNode(struct Node *head, int data, unsigned int size) {
    struct Node *temp;
    temp->data = data;
    temp->next = NULL;
    for (int i = 0; i < size; i++) {
        head->next = temp;
        head = head->next;
    }
}
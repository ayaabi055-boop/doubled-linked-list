#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int value) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = value;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void searchNode(struct Node* head, int value) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d found\n", value);
            return;
        }
        temp = temp->next;
    }

    printf("%d not found\n", value);
}

int main() {
    struct Node* head = createNode(10);

    head->next = createNode(25);
    head->next->prev = head;

    head->next->next = createNode(30);
    head->next->next->prev = head->next;

    searchNode(head, 25);
    searchNode(head, 17);

    return 0;
}
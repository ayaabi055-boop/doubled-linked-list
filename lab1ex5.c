#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = value;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void traverseForward(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void traverseBackward(struct Node* head) {
    if (head == NULL)
        return;

    while (head->next != NULL)
        head = head->next;

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = createNode(10);

    head->next = createNode(15);
    head->next->prev = head;

    head->next->next = createNode(20);
    head->next->next->prev = head->next;

    head->next->next->next = createNode(25);
    head->next->next->next->prev = head->next->next;

    printf("Forward: ");
    traverseForward(head);

    printf("Backward: ");
    traverseBackward(head);

    return 0;
}
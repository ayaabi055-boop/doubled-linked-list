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

void insertAtBeginning(struct Node** head, int value) {
    struct Node* n = createNode(value);
    n->next = *head;

    if (*head != NULL)
        (*head)->prev = n;

    *head = n;
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* n = createNode(value);

    if (*head == NULL) {
        *head = n;
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

void insertAfter(struct Node* head, int value, int target) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL)
        return;

    struct Node* n = createNode(value);
    n->prev = temp;
    n->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;
}

void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 15);
    insertAtBeginning(&head, 10);

    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);

    displayList(head);

    insertAfter(head, 17, 15);

    displayList(head);

    return 0;
}
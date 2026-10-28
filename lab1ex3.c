#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int value) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = value;
    n->next = NULL;

    if (*head == NULL) {
        n->prev = NULL;
        *head = n;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

void createList(struct Node** head) {
    insertAtEnd(head, 10);
    insertAtEnd(head, 15);
    insertAtEnd(head, 20);
    insertAtEnd(head, 25);
    insertAtEnd(head, 30);
}

void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);

        if (head->next != NULL)
            printf(" <-> ");

        head = head->next;
    }
    printf("\n");
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL)
        return;

    struct Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL)
        return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

void deleteNode(struct Node** head, int target) {
    struct Node* current = *head;

    while (current != NULL && current->data != target)
        current = current->next;

    if (current == NULL)
        return;

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
}

void freeList(struct Node** head) {
    while (*head != NULL) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    createList(&head);
    printf("Original: ");
    displayList(head);

    deleteAtBeginning(&head);
    printf("After deleting first: ");
    displayList(head);

    deleteAtEnd(&head);
    printf("After deleting last: ");
    displayList(head);

    deleteNode(&head, 20);
    printf("After deleting 20: ");
    displayList(head);

    freeList(&head);

    return 0;
}
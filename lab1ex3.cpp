#include <cstdio>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* n = new Node;
    n->data = value;
    n->next = NULL;

    if (head == NULL) {
        n->prev = NULL;
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

void createList(Node*& head) {
    insertAtEnd(head, 10);
    insertAtEnd(head, 15);
    insertAtEnd(head, 20);
    insertAtEnd(head, 25);
    insertAtEnd(head, 30);
}

void displayList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);

        if (head->next != NULL)
            printf(" <-> ");

        head = head->next;
    }
    printf("\n");
}

void deleteAtBeginning(Node*& head) {
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

void deleteAtEnd(Node*& head) {
    if (head == NULL)
        return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    delete temp;
}

void deleteNode(Node*& head, int target) {
    Node* current = head;

    while (current != NULL && current->data != target)
        current = current->next;

    if (current == NULL)
        return;

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    delete current;
}

void freeList(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;

    createList(head);
    printf("Original: ");
    displayList(head);

    deleteAtBeginning(head);
    printf("After deleting first: ");
    displayList(head);

    deleteAtEnd(head);
    printf("After deleting last: ");
    displayList(head);

    deleteNode(head, 20);
    printf("After deleting 20: ");
    displayList(head);

    freeList(head);

    return 0;
}
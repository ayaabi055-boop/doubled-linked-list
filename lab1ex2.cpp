#include <cstdio>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* n = new Node{value, NULL, head};

    if (head != NULL)
        head->prev = n;

    head = n;
}

void insertAtEnd(Node*& head, int value) {
    Node* n = new Node{value, NULL, NULL};

    if (head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

void insertAfter(Node* head, int value, int target) {
    Node* temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL)
        return;

    Node* n = new Node{value, temp, temp->next};

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;
}

void displayList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertAtBeginning(head, 15);
    insertAtBeginning(head, 10);

    insertAtEnd(head, 20);
    insertAtEnd(head, 25);
    insertAtEnd(head, 30);

    displayList(head);

    insertAfter(head, 17, 15);

    displayList(head);

    return 0;
}
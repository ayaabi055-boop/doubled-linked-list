#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void traverseForward(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void traverseBackward(Node* head) {
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
    Node* head = new Node{10, NULL, NULL};
    head->next = new Node{15, head, NULL};
    head->next->next = new Node{20, head->next, NULL};
    head->next->next->next =
        new Node{25, head->next->next, NULL};

    printf("Forward: ");
    traverseForward(head);

    printf("Backward: ");
    traverseBackward(head);

    return 0;
}
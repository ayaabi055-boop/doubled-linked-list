#include <cstdio>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void searchNode(Node* head, int value) {
    Node* temp = head;

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
    Node* head = new Node{10, NULL, NULL};
    head->next = new Node{25, NULL, head};
    head->next->next = new Node{30, NULL, head->next};

    searchNode(head, 25);
    searchNode(head, 17);

    return 0;
}
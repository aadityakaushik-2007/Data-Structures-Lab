#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (head == NULL) return true;
    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

int main() {
    Node* head = new Node{1, NULL};
    Node* second = new Node{2, NULL};
    Node* third = new Node{3, NULL};

    head->next = second;
    second->next = third;
    third->next = head;

    if (isCircular(head))
        cout << "Linked List is Circular";
    else
        cout << "Linked List is Not Circular";

    return 0;
}
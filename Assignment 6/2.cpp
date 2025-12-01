#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class CircularList {
    Node* head;
public:
    CircularList() : head(nullptr) {}

    void insert(int x) {
        Node* node = new Node(x);
        if (!head) {
            head = node;
            head->next = head;
            return;
        }
        Node* cur = head;
        while (cur->next != head) cur = cur->next;
        cur->next = node;
        node->next = head;
    }

    void display() {
        if (!head) return;
        Node* cur = head;
        do {
            cout << cur->data << " ";
            cur = cur->next;
        } while (cur != head);
        cout << head->data;
    }
};

int main() {
    CircularList cl;

    cl.insert(10);
    cl.insert(20);
    cl.insert(30);
    cl.insert(40);

    cl.display();

    return 0;
}
#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v) : data(v), prev(nullptr), next(nullptr) {}
};

struct CNode {
    int data;
    CNode* next;
    CNode(int v) : data(v), next(nullptr) {}
};

class DoublyList {
public:
    DNode* head;
    DoublyList() : head(nullptr) {}

    void insert(int x) {
        DNode* node = new DNode(x);
        if (!head) {
            head = node;
            return;
        }
        DNode* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
        node->prev = cur;
    }

    int size() {
        int c = 0;
        DNode* cur = head;
        while (cur) {
            c++;
            cur = cur->next;
        }
        return c;
    }
};

class CircularList {
public:
    CNode* head;
    CircularList() : head(nullptr) {}

    void insert(int x) {
        CNode* node = new CNode(x);
        if (!head) {
            head = node;
            head->next = head;
            return;
        }
        CNode* cur = head;
        while (cur->next != head) cur = cur->next;
        cur->next = node;
        node->next = head;
    }

    int size() {
        if (!head) return 0;
        int c = 0;
        CNode* cur = head;
        do {
            c++;
            cur = cur->next;
        } while (cur != head);
        return c;
    }
};

int main() {
    DoublyList dl;
    dl.insert(10);
    dl.insert(20);
    dl.insert(30);

    CircularList cl;
    cl.insert(5);
    cl.insert(15);
    cl.insert(25);
    cl.insert(35);

    cout << "Size of Doubly Linked List: " << dl.size() << endl;
    cout << "Size of Circular Linked List: " << cl.size() << endl;

    return 0;
}
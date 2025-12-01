#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) { data = x; next = nullptr; }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if(!head) { head = n; return; }
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = n;
    }

    void findMiddle() {
        if(!head) { cout << "List is empty\n"; return; }
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data << endl;
    }

    void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->data;
            if(temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    int arr[] = {1,2,3,4,5};
    for(int x : arr) ll.insertEnd(x);
    ll.display();
    cout << "Middle element: ";
    ll.findMiddle();
}
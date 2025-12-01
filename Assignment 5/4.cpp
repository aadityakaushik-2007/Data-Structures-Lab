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

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->data;
            if(temp->next) cout << "->";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }
};

int main() {
    LinkedList ll;
    int arr[] = {1,2,3,4};
    for(int x : arr) ll.insertEnd(x);

    cout << "Original List: ";
    ll.display();

    ll.reverse();

    cout << "Reversed List: ";
    ll.display();
}
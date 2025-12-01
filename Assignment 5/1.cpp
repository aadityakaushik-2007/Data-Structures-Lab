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

    void insertBeginning(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if(!head) { head = n; return; }
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = n;
    }

    void insertAfter(int key, int x) {
        Node* temp = head;
        while(temp && temp->data != key) temp = temp->next;
        if(temp) {
            Node* n = new Node(x);
            n->next = temp->next;
            temp->next = n;
        }
    }

    void insertBefore(int key, int x) {
        if(!head) return;
        if(head->data == key) { insertBeginning(x); return; }
        Node* temp = head;
        while(temp->next && temp->next->data != key) temp = temp->next;
        if(temp->next) {
            Node* n = new Node(x);
            n->next = temp->next;
            temp->next = n;
        }
    }

    void deleteBeginning() {
        if(!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if(!head) return;
        if(!head->next) { delete head; head = nullptr; return; }
        Node* temp = head;
        while(temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int key) {
        if(!head) return;
        if(head->data == key) { deleteBeginning(); return; }
        Node* temp = head;
        while(temp->next && temp->next->data != key) temp = temp->next;
        if(temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    int search(int key) {
        Node* temp = head;
        int pos = 1;
        while(temp) {
            if(temp->data == key) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    int choice, value, key;
    while(true) {
        cout << "1.Insert Beginning 2.Insert End 3.Insert After 4.Insert Before\n";
        cout << "5.Delete Beginning 6.Delete End 7.Delete Node 8.Search Node 9.Display 10.Exit\n";
        cin >> choice;
        switch(choice) {
            case 1: cin >> value; ll.insertBeginning(value); break;
            case 2: cin >> value; ll.insertEnd(value); break;
            case 3: cin >> key >> value; ll.insertAfter(key, value); break;
            case 4: cin >> key >> value; ll.insertBefore(key, value); break;
            case 5: ll.deleteBeginning(); break;
            case 6: ll.deleteEnd(); break;
            case 7: cin >> key; ll.deleteNode(key); break;
            case 8: cin >> key; {
                int pos = ll.search(key);
                if(pos == -1) cout << "Not found\n";
                else cout << "Position: " << pos << endl;
                break;
            }
            case 9: ll.display(); break;
            case 10: return 0;
        }
    }
}
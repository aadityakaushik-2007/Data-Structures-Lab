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

    int countAndDelete(int key) {
        int count = 0;
        while(head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        Node* curr = head;
        while(curr && curr->next) {
            if(curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                count++;
            } else {
                curr = curr->next;
            }
        }
        return count;
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
    int arr[] = {1,2,1,2,1,3,1};
    int n = 7;
    for(int i = 0; i<n; i++) ll.insertEnd(arr[i]);
    int key = 1;
    int cnt = ll.countAndDelete(key);
    cout << "Count: " << cnt << endl;
    cout << "Updated Linked List: ";
    ll.display();
}
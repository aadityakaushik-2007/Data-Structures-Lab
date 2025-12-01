#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int v) : data(v), next(nullptr) {}
};

class CircularList {
    CNode* head;
public:
    CircularList() : head(nullptr) {}

    void insertAtBeginning(int x) {
        CNode* node = new CNode(x);
        if (!head) {
            head = node;
            head->next = head;
            return;
        }
        CNode* tail = head;
        while (tail->next != head) tail = tail->next;
        node->next = head;
        tail->next = node;
        head = node;
    }

    void insertAtEnd(int x) {
        CNode* node = new CNode(x);
        if (!head) {
            head = node;
            head->next = head;
            return;
        }
        CNode* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = node;
        node->next = head;
    }

    bool insertAfter(int key, int x) {
        if (!head) return false;
        CNode* cur = head;
        do {
            if (cur->data == key) {
                CNode* node = new CNode(x);
                node->next = cur->next;
                cur->next = node;
                return true;
            }
            cur = cur->next;
        } while (cur != head);
        return false;
    }

    bool insertBefore(int key, int x) {
        if (!head) return false;
        if (head->data == key) {
            insertAtBeginning(x);
            return true;
        }
        CNode* prev = head;
        CNode* cur = head->next;
        while (cur != head) {
            if (cur->data == key) {
                CNode* node = new CNode(x);
                prev->next = node;
                node->next = cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    bool deleteNode(int key) {
        if (!head) return false;
        if (head->next == head) {
            if (head->data == key) {
                delete head;
                head = nullptr;
                return true;
            }
            return false;
        }
        if (head->data == key) {
            CNode* tail = head;
            while (tail->next != head) tail = tail->next;
            CNode* t = head;
            head = head->next;
            tail->next = head;
            delete t;
            return true;
        }
        CNode* prev = head;
        CNode* cur = head->next;
        while (cur != head) {
            if (cur->data == key) {
                prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    int search(int key) {
        if (!head) return -1;
        int pos = 1;
        CNode* cur = head;
        do {
            if (cur->data == key) return pos;
            cur = cur->next;
            pos++;
        } while (cur != head);
        return -1;
    }

    void display() {
        if (!head) {
            cout << "Circular List is empty\n";
            return;
        }
        CNode* cur = head;
        cout << "Head -> ";
        do {
            cout << cur->data << " -> ";
            cur = cur->next;
        } while (cur != head);
        cout << "(back to head)\n";
    }
};

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v) : data(v), prev(nullptr), next(nullptr) {}
};

class DoublyList {
    DNode* head;
public:
    DoublyList() : head(nullptr) {}

    void insertAtBeginning(int x) {
        DNode* node = new DNode(x);
        if (!head) {
            head = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
    }

    void insertAtEnd(int x) {
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

    bool insertAfter(int key, int x) {
        DNode* cur = head;
        while (cur) {
            if (cur->data == key) {
                DNode* node = new DNode(x);
                node->next = cur->next;
                node->prev = cur;
                if (cur->next) cur->next->prev = node;
                cur->next = node;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool insertBefore(int key, int x) {
        if (!head) return false;
        if (head->data == key) {
            insertAtBeginning(x);
            return true;
        }
        DNode* cur = head->next;
        while (cur) {
            if (cur->data == key) {
                DNode* node = new DNode(x);
                node->prev = cur->prev;
                node->next = cur;
                cur->prev->next = node;
                cur->prev = node;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool deleteNode(int key) {
        DNode* cur = head;
        while (cur) {
            if (cur->data == key) {
                if (cur->prev) cur->prev->next = cur->next;
                else head = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                delete cur;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    int search(int key) {
        DNode* cur = head;
        int pos = 1;
        while (cur) {
            if (cur->data == key) return pos;
            cur = cur->next;
            pos++;
        }
        return -1;
    }

    void display() {
        if (!head) {
            cout << "Doubly List is empty\n";
            return;
        }
        DNode* cur = head;
        cout << "NULL <- ";
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " <-> ";
            cur = cur->next;
        }
        cout << " -> NULL\n";
    }
};

void circularMenu(CircularList &clist) {
    while (true) {
        cout << "\n--- Circular Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after\n4. Insert before\n5. Delete\n6. Search\n7. Display\n8. Back\nChoose: ";
        int c; cin >> c;
        if (c == 1) { int v; cin >> v; clist.insertAtBeginning(v); }
        else if (c == 2) { int v; cin >> v; clist.insertAtEnd(v); }
        else if (c == 3) { int k,v; cin >> k >> v; if (!clist.insertAfter(k,v)) cout << "Not found\n"; }
        else if (c == 4) { int k,v; cin >> k >> v; if (!clist.insertBefore(k,v)) cout << "Not found\n"; }
        else if (c == 5) { int k; cin >> k; if (!clist.deleteNode(k)) cout << "Not found\n"; }
        else if (c == 6) { int k; cin >> k; int p = clist.search(k); if (p==-1) cout << "Not found\n"; else cout << p << "\n"; }
        else if (c == 7) clist.display();
        else if (c == 8) break;
    }
}

void doublyMenu(DoublyList &dlist) {
    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after\n4. Insert before\n5. Delete\n6. Search\n7. Display\n8. Back\nChoose: ";
        int c; cin >> c;
        if (c == 1) { int v; cin >> v; dlist.insertAtBeginning(v); }
        else if (c == 2) { int v; cin >> v; dlist.insertAtEnd(v); }
        else if (c == 3) { int k,v; cin >> k >> v; if (!dlist.insertAfter(k,v)) cout << "Not found\n"; }
        else if (c == 4) { int k,v; cin >> k >> v; if (!dlist.insertBefore(k,v)) cout << "Not found\n"; }
        else if (c == 5) { int k; cin >> k; if (!dlist.deleteNode(k)) cout << "Not found\n"; }
        else if (c == 6) { int k; cin >> k; int p = dlist.search(k); if (p==-1) cout << "Not found\n"; else cout << p << "\n"; }
        else if (c == 7) dlist.display();
        else if (c == 8) break;
    }
}

int main() {
    CircularList clist;
    DoublyList dlist;
    while (true) {
        cout << "\n1. Circular List\n2. Doubly List\n3. Exit\nChoose: ";
        int c; cin >> c;
        if (c == 1) circularMenu(clist);
        else if (c == 2) doublyMenu(dlist);
        else if (c == 3) break;
    }
    return 0;
}
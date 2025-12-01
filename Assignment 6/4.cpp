#include <iostream>
#include <string>
using namespace std;

struct DNode {
    char data;
    DNode* prev;
    DNode* next;
    DNode(char c) : data(c), prev(nullptr), next(nullptr) {}
};

class DoublyList {
public:
    DNode* head;
    DoublyList() : head(nullptr) {}
    void insertEnd(char c) {
        DNode* node = new DNode(c);
        if (!head) { head = node; return; }
        DNode* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
        node->prev = cur;
    }
    bool isPalindrome() {
        if (!head || !head->next) return true;
        DNode* left = head;
        DNode* right = head;
        while (right->next) right = right->next;
        while (left != right && left->prev != right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
    void clear() {
        DNode* cur = head;
        while (cur) {
            DNode* t = cur;
            cur = cur->next;
            delete t;
        }
        head = nullptr;
    }
};

int main() {
    string s;
    cout << "Enter string (characters only, no spaces): ";
    if (!(cin >> s)) return 0;
    DoublyList dl;
    for (char c : s) dl.insertEnd(c);
    bool pal = dl.isPalindrome();
    cout << (pal ? "Palindrome" : "Not Palindrome") << endl;
    dl.clear();
    return 0;
}

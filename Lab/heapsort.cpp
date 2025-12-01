#include <iostream>
using namespace std;

struct Node{
int data;
Node *left;
Node *right;
};

Node* larger(Node* x) {
    if (!x) return nullptr;
    Node* L = x->left;
    Node* R = x->right;
    if (!L && !R) return nullptr;
    if (L && R) {
        if (L->data >= R->data) {
            return (L->data > x->data) ? L : nullptr;
        } else {
            return (R->data > x->data) ? R : nullptr;
        }
    }
    if (L) {return (L->data > x->data) ? L : nullptr;}
    else {return (R->data > x->data) ? R : nullptr;}
}
void heap(Node* root) {
    Node* cur = root;
    while (true) {
        Node* nxt = larger(cur);
        if (!nxt) break;      
        int temp = cur->data;
        cur->data = nxt->data;
        nxt->data = temp;
        cur = nxt;
    }
}
void buildHeap(Node* nodes[], int n) {
    for (int i = n/2 - 1; i >= 0; --i) {
        heap(nodes[i]);
    }
}
void detachLast(Node* nodes[], int last) {
    if (last <= 0) return;           
    int p = (last - 1) / 2; 
    if (2*p + 1 == last) nodes[p]->left  = nullptr; 
    else nodes[p]->right = nullptr;  
}


void heapSort(Node* nodes[], int n) {
    buildHeap(nodes, n);
    for (int last = n - 1; last > 0; --last) {
        int tmp = nodes[0]->data;
        nodes[0]->data = nodes[last]->data;
        nodes[last]->data = tmp;
        detachLast(nodes, last);
        heap(nodes[0]);
    }
}


int main(){
    return 0;
}
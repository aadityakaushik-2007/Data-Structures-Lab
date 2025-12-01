#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    void set(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

bool isBSTUtil(node* root, node* &prev){
    if(root == nullptr) return true;
    if(!isBSTUtil(root->left, prev)) return false;
    if(prev != nullptr && root->data <= prev->data) return false;
    prev = root;
    return isBSTUtil(root->right, prev);
}

bool isBST(node* root){
    node* prev = nullptr;
    return isBSTUtil(root, prev);
}

int main(){
    node n1,n2,n3,n4,n5,n6,n7;
    n1.set(8);
    n2.set(4);
    n3.set(12);
    n4.set(2);
    n5.set(6);
    n6.set(10);
    n7.set(14);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    if(isBST(&n1)) cout<<"It is a BST"<<endl;
    else cout<<"Not a BST"<<endl;

    return 0;
}

#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    void addnode(int i){
        data = i;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(node* ptr){
    node* root = ptr;
    if(ptr==nullptr) return;
    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* ptr){
    node* root = ptr;
    if(ptr==nullptr) return;
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}
void postorder(node* ptr){
    node* root = ptr;
    if(ptr==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"  ";
}

int main(){
    node n1,n2,n3,n4,n5,n6;
    n1.addnode(11);
    n2.addnode(10);
    n3.addnode(9);
    n4.addnode(8);
    n5.addnode(7);
    n6.addnode(6);
    node* ptr1 = &n1;
    node* ptr2 = &n2;
    node* ptr3 = &n3;
    node* ptr4 = &n4;
    node* ptr5 = &n5;
    node* ptr6 = &n6;
    n1.left = ptr2;
    n1.right = ptr3;
    n2.left = ptr4;
    n2.right = ptr5;
    n3.left = ptr6;
    int x = 0;
    while(true){
        cout<<"Which travel: \n"<<"1) Preorder \n"<<"2)in order \n"<<"3) post order \n"<<"4) exit"<<endl;
        cin>>x;
        switch(x){
            case 1:
                preorder(ptr1);
                cout<<endl;
                break;
            case 2:
                inorder(ptr1);
                cout<<endl;
                break;
            case 3:
                postorder(ptr1);
                cout<<endl;
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}
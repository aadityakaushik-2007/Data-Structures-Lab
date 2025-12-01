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

int RSearch(node* ptr, int i){
    if(ptr == nullptr) return 0;
    if(ptr->data == i) return 1;
    if(i < ptr->data) return RSearch(ptr->left,i);
    else return RSearch(ptr->right,i);
}

bool ISearch(node*ptr, int i){
    bool found = false;
    node* root = ptr;
    while(root!=nullptr){
        if(root->data == i){
            found = true;
            break;
        }
        else if(root->data > i){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return found;
}

int maxx(node* ptr){
    node* root = ptr;
    while(root->right!=nullptr){
        root = root->right;
    }
    return root->data;
}

int minn(node* ptr){
    node* root = ptr;
    while(root->left!=nullptr){
        root = root->left;
    }
    return root->data;
}

node* pre = nullptr;
node* succ = nullptr;

void inorder(node* r, node* ptr){
    node* root = r;
    if(root==nullptr) return;
    inorder(root->left, ptr);
    if(root->data > ptr->data && succ==nullptr){
        succ = root;
    }
    else if(root->data > ptr->data && succ->data > root->data){
        succ = root;
    }
    if(root->data < ptr->data && pre==nullptr){
        pre = root;
    }
    else if(root->data < ptr->data && pre->data < root->data){
        pre = root;
    }
    inorder(root->right, ptr);
}

node* insert(node* root,int x){
    if(root==nullptr){
        node* t = new node;
        t->set(x);
        return t;
    }
    if(x < root->data){
        root->left = insert(root->left,x);
    }
    else if(x > root->data){
        root->right = insert(root->right,x);
    }
    return root;
}

int depth(node* root){
    if(root==nullptr) return 0;
    int lh = depth(root->left);
    int rh = depth(root->right);
    if(lh > rh) return lh+1;
    else return rh+1;
}

node* Delete(node* root, int key){
    if(root == nullptr) return root;

    if(key < root->data){
        root->left = Delete(root->left, key);
    }
    else if(key > root->data){
        root->right = Delete(root->right, key);
    }
    else{
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        else if(root->left == nullptr){
            node* t = root->right;
            delete root;
            return t;
        }
        else if(root->right == nullptr){
            node* t = root->left;
            delete root;
            return t;
        }
        else{
            node* succ = root->right;
            while(succ->left != nullptr){
                succ = succ->left;
            }
            root->data = succ->data;
            root->right = Delete(root->right, succ->data);
        }
    }
    return root;
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

    node* root = &n1;

    cout<<"Current max depth: "<<depth(root)<<endl;

    int ins;
    cout<<"Enter value to insert: "<<endl;
    cin>>ins;
    root = insert(root,ins);
    cout<<"Max depth after insert: "<<depth(root)<<endl;
    int y;
    cout<<"Enter number to search: "<<endl;
    cin>>y;
    int x = RSearch(root, y);
    if(x) cout<<"Found from recursive search"<<endl;
    else cout<<"Not found from recursive search"<<endl;
    int z = ISearch(root, y);
    if(z) cout<<"Found from iterative search"<<endl;
    else cout<<"Not found from iterative search"<<endl;
    cout<<"Max element: "<<maxx(root)<<" and Min element: "<<minn(root)<<endl;
    inorder(root,&n5);
    cout<<" inorder succ and pre of "<<n5.data<<" is: "<<succ->data<<" and "<<pre->data<<endl;
    root = Delete(&n1, 14);
    return 0;
}

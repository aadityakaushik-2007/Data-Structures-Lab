#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, size, capacity;
public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[cap];
        front = 0;
        size = 0;
        rear = -1;
    }
    void enqueue(int x) {
        if (size == capacity) return;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }
    void dequeue() {
        if (size == 0) return;
        front = (front + 1) % capacity;
        size--;
    }
    int peek() {
        if (size == 0) return -1;
        return arr[front];
    }
    bool isEmpty() { return size == 0; }
    ~Queue() { delete[] arr; }
};

class Stack {
    int* arr;
    int top, cap;
public:
    Stack(int c) {
        cap = c;
        arr = new int[c];
        top = -1;
    }
    void push(int x) {
        if (top == cap - 1) return;
        arr[++top] = x;
    }
    void pop() {
        if (top == -1) return;
        top--;
    }
    int peek() {
        if (top == -1) return -1;
        return arr[top];
    }
    bool isEmpty() { return top == -1; }
    ~Stack() { delete[] arr; }
};

class node{
public:
    int data;
    node* next;
    node(int x, node* nxt = nullptr){
        data = x;
        next = nxt;
    }
};

node* finder(node* arr[], int n, int x){
    for(int i = 0; i < n; i++){
        if(arr[i]->data == x){
            return arr[i];
        }
    }
    return nullptr;
}

int nfinder(node* arr[], int n, int x){
    for(int i = 0; i < n; i++){
        if(arr[i]->data == x){
            return i;
        }
    }
    return -1;
}

void printadj(node* arr[], int n){
    for(int i = 0; i < n; i++){
        node* curr = arr[i];
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->next != nullptr) cout << "->";
            curr = curr->next;
        }
        cout << endl;
    }
}

void bfs(node* arr[], int n, int vst[]){
    if(n == 0) return;
    Queue q(n);
    q.enqueue(arr[0]->data);
    vst[0] = 1;

    while(!q.isEmpty()){
        int u = q.peek();
        cout << u << " ";
        q.dequeue();

        node* curr = finder(arr, n, u);
        if(!curr) continue;

        while(curr->next != nullptr){
            curr = curr->next;
            int idx = nfinder(arr, n, curr->data);
            if(idx != -1 && vst[idx] == 0){
                vst[idx] = 1;
                q.enqueue(curr->data);
            }
        }
    }
}

void dfs(node* arr[], int n, int vst[]){
    if(n == 0) return;
    Stack st(n);
    st.push(arr[0]->data);
    vst[0] = 1;
    cout << arr[0]->data << " ";

    while(!st.isEmpty()){
        int u = st.peek();
        node* curr = finder(arr, n, u);
        if(!curr){
            st.pop();
            continue;
        }
        node* temp = curr->next;
        bool pushed = false;
        while(temp != nullptr){
            int idx = nfinder(arr, n, temp->data);
            if(idx != -1 && vst[idx] == 0){
                vst[idx] = 1;
                st.push(temp->data);
                cout << temp->data << " ";
                pushed = true;
                break;
            }
            temp = temp->next;
        }
        if(!pushed){
            st.pop();
        }
    }
}

int main(){
    int n,m;
    cout << "Enter no. of vertices and edges: \n";
    cin >> n >> m;

    node** adj = new node*[n];
    for(int i = 0; i < n; i++){
        int z;
        cout << "Enter value of vertex " << i + 1 << endl;
        cin >> z;
        adj[i] = new node(z);
    }

    for(int i = 0; i < m; i++){
        int u,v;
        cout << "Enter edge (u v) " << i + 1 << endl;
        cin >> u >> v;

        node* curr = finder(adj, n, u);
        if(curr){
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = new node(v);
        }

        curr = finder(adj, n, v);
        if(curr){
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = new node(u);
        }
    }

    printadj(adj, n);

    int* vst = new int[n];
    for(int i = 0; i < n; i++) vst[i] = 0;

    cout << "BFS: ";
    bfs(adj, n, vst);

    for(int i = 0; i < n; i++) vst[i] = 0;

    cout << "\nDFS: ";
    dfs(adj, n, vst);

    for(int i = 0; i < n; i++){
        node* curr = adj[i];
        while(curr){
            node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }
    delete[] adj;
    delete[] vst;

    return 0;
}

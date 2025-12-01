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
    node(int x, node* nxt=nullptr){
        data = x;
        next = nxt;
    }
};
node* finder(node* arr[],int n,int x){
    for(int i = 0;i<n;i++){
        if(arr[i]->data==x){
            return arr[i];
        }
    }
}
int nfinder(node* arr[], int n, int x){
    for(int i = 0;i<n;i++){
        if(arr[i]->data==x){
            return i;
        }
    }
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
    Queue q(n);
    q.enqueue(arr[0]->data);
    vst[0]=1;
    node* curr = arr[0];
    while(curr->next != nullptr){
        curr = curr->next;
        if(vst[nfinder(arr,n,curr->data)]==0){
            q.enqueue(curr->data); 
            vst[nfinder(arr,n,curr->data)]=1;
        }
    }
    cout<<q.peek()<<" ";
    q.dequeue();
    while(!q.isEmpty()){
        node* curr = finder(arr,n,q.peek());
        while(curr->next != nullptr){
            curr = curr->next;
            if(vst[nfinder(arr,n,curr->data)]==0){
                q.enqueue(curr->data); 
                vst[nfinder(arr,n,curr->data)]=1;
            }
        }
        cout<<q.peek()<<" ";
        q.dequeue();
    }
}

void dfs(node* arr[], int n, int vst[]){
    Stack st(n);
    st.push(arr[0]->data);
    cout<<st.peek()<<" ";
    vst[0]=1;
    while(!st.isEmpty()){
        node* curr = finder(arr,n,(st.peek()));
        if(vst[nfinder(arr, n, (curr->next->data))] == 0){
            curr = curr->next;
            st.push(curr->data);
            cout<<st.peek()<<" ";
            vst[nfinder(arr, n, (curr->data))]=1;
        }
        else{
            node* ncr = curr;
            while(ncr->next!=nullptr){
                ncr = ncr->next;
            }
            while((curr->next!=nullptr)&&(vst[nfinder(arr,n,(curr->next->data))]==1)){
                curr = curr->next;
            }

            if(curr==ncr){
                st.pop();
            }
            else{
                st.push(curr->next->data);
                cout<<st.peek()<<" ";
                vst[nfinder(arr, n, (curr->next->data))]=1;
            }

        }
    }
}

int main(){
    int n,m;
    cout<<"Enter no. of vertices and edges: \n";
    cin>>n>>m;
    node** adj = new node*[n];
    for(int i = 0;i<n;i++){
        int z;
        cout<<"Enter value of vertex "<<i+1<<endl;
        cin>>z;
        adj[i]=new node(z);
    }
    for(int i = 0;i<m;i++){
        int u,v;
        cout<<"Enter edges (u,v)"<<i+1<<endl;
        cin>>u>>v;
        node* curr;
        curr = finder(adj,n,u);
        while(!(curr->next==nullptr)){
            curr = curr->next;
        }
        curr->next = new node(v);
        curr = finder(adj,n,v);
        while(!(curr->next==nullptr)){
            curr = curr->next;
        }
        curr->next = new node(u);
    }
    printadj(adj,n);
    int* vst = new int[n]();
    bfs(adj, n, vst);
    for(int i = 0; i < n; i++) {vst[i] = 0;}
    cout<<"\n This is dfs now: "<<endl;
    dfs(adj, n, vst);
    return 0;
}
#include <iostream>
using namespace std;

class Queue{
    int arr[100];
    int front;
    int rear;
public:
    Queue(){
        front = 0;
        rear = -1;
    }
    void enqueue(int x){
        if(rear == 99) return;
        rear++;
        arr[rear] = x;
    }
    int dequeue(){
        if(front > rear) return -1;
        int x = arr[front];
        front++;
        return x;
    }
    int isEmpty(){
        return front > rear;
    }
    int size(){
        return rear - front + 1;
    }
};

int main(){
    int n;
    cin>>n;
    Queue q, first;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.enqueue(x);
    }
    int half = n/2;
    for(int i=0;i<half;i++){
        first.enqueue(q.dequeue());
    }
    for(int i=0;i<half;i++){
        q.enqueue(first.dequeue());
        q.enqueue(q.dequeue());
    }
    int flag=1;
    while(!q.isEmpty()){
        if(!flag) cout<<" ";
        cout<<q.dequeue();
        flag=0;
    }
    return 0;
}

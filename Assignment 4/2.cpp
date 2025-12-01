#include <iostream>
using namespace std;

class cqueue{
    int arr[100];
    int front;
    int rear;
    int size;
public:
    cqueue(){
        size = 100;
        front = -1;
        rear = -1;
    }
    int isEmpty(){
        if(front == -1) return 1;
        return 0;
    }
    int isFull(){
        if((front == 0 && rear == size - 1) || (rear + 1) % size == front) return 1;
        return 0;
    }
    void enqueue(){
        if(isFull()){
            cout<<"Overflow"<<endl;
        }else{
            int x;
            cout<<"Enter number to enqueue"<<endl;
            cin>>x;
            if(isEmpty()){
                front = 0;
                rear = 0;
            }else{
                rear = (rear + 1) % size;
            }
            arr[rear] = x;
        }
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"underflow"<<endl;
        }else{
            cout<<arr[front]<<endl;
            if(front == rear){
                front = -1;
                rear = -1;
            }else{
                front = (front + 1) % size;
            }
        }
    }
    void peek(){
        if(isEmpty()){
            cout<<"underflow"<<endl;
        }else{
            cout<<arr[front]<<endl;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Empty"<<endl;
        }else{
            int i = front;
            while(true){
                cout<<arr[i]<<endl;
                if(i == rear) break;
                i = (i + 1) % size;
            }
        }
    }
};

int main(){
    cqueue q;
    int x;
    while(true){
        cout<<"CHOOSE\n";
        cout<<"1) enqueue\n";
        cout<<"2) dequeue\n";
        cout<<"3) Check for empty\n";
        cout<<"4) Check for full\n";
        cout<<"5) display\n";
        cout<<"6) peek\n";
        cout<<"7) END"<<endl;
        if(!(cin>>x)) return 0;
        switch(x){
            case 1: q.enqueue(); break;
            case 2: q.dequeue(); break;
            case 3: cout<<q.isEmpty()<<endl; break;
            case 4: cout<<q.isFull()<<endl; break;
            case 5: q.display(); break;
            case 6: q.peek(); break;
            case 7: return 0;
        }
    }
    return 0;
}

#include <iostream>
using namespace std;

class Queue{
    int arr[100];
    int front, rear, cnt;
public:
    Queue(){
        front = 0;
        rear = -1;
        cnt = 0;
    }
    int isEmpty(){
        return cnt == 0;
    }
    int isFull(){
        return cnt == 100;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Overflow"<<endl;
        }else{
            rear = (rear + 1) % 100;
            arr[rear] = x;
            cnt++;
        }
    }
    int frontVal(){
        if(isEmpty()){
            return -1;
        }else{
            return arr[front];
        }
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
        }else{
            front = (front + 1) % 100;
            cnt--;
        }
    }
};

class StackTwoQ{
    Queue q1, q2;
public:
    void push(int x){
        q2.enqueue(x);
        while(!q1.isEmpty()){
            q2.enqueue(q1.frontVal());
            q1.dequeue();
        }
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop(){
        if(q1.isEmpty()){
            cout<<"underflow"<<endl;
        }else{
            cout<<q1.frontVal()<<endl;
            q1.dequeue();
        }
    }
    void peek(){
        if(q1.isEmpty()){
            cout<<"underflow"<<endl;
        }else{
            cout<<q1.frontVal()<<endl;
        }
    }
    int isEmpty(){
        return q1.isEmpty();
    }
};

class StackOneQ{
    Queue q;
public:
    void push(int x){
        int s = 0;
        Queue temp = q;
        while(!temp.isEmpty()){
            s++;
            temp.dequeue();
        }
        q.enqueue(x);
        for(int i = 0; i < s; i++){
            int v = q.frontVal();
            q.dequeue();
            q.enqueue(v);
        }
    }
    void pop(){
        if(q.isEmpty()){
            cout<<"underflow"<<endl;
        }else{
            cout<<q.frontVal()<<endl;
            q.dequeue();
        }
    }
    void peek(){
        if(q.isEmpty()){
            cout<<"underflow"<<endl;
        }else{
            cout<<q.frontVal()<<endl;
        }
    }
    int isEmpty(){
        return q.isEmpty();
    }
};

int main(){
    int t;
    cout<<"Choose\n1) Stack using two queues\n2) Stack using one queue"<<endl;
    cin>>t;
    if(t == 1){
        StackTwoQ s;
        int x = 0;
        while(true){
            cout<<"CHOOSE\n1) push\n2) pop\n3) peek\n4) isEmpty\n5) END"<<endl;
            cin>>x;
            switch(x){
                case 1:{
                    int v;
                    cout<<"Enter number to push"<<endl;
                    cin>>v;
                    s.push(v);
                    break;
                }
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.peek();
                    break;
                case 4:
                    if(s.isEmpty()) cout<<"Empty"<<endl;
                    else cout<<"Not empty"<<endl;
                    break;
                case 5:
                    return 0;
            }
        }
    }else if(t == 2){
        StackOneQ s;
        int x = 0;
        while(true){
            cout<<"CHOOSE\n1) push\n2) pop\n3) peek\n4) isEmpty\n5) END"<<endl;
            cin>>x;
            switch(x){
                case 1:{
                    int v;
                    cout<<"Enter number to push"<<endl;
                    cin>>v;
                    s.push(v);
                    break;
                }
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.peek();
                    break;
                case 4:
                    if(s.isEmpty()) cout<<"Empty"<<endl;
                    else cout<<"Not empty"<<endl;
                    break;
                case 5:
                    return 0;
            }
        }
    }
    return 0;
}

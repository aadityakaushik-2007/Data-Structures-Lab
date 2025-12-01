#include <iostream>
using namespace std;

class queuee{
    int arr[100];
    int front = -1;
    int rear = -1;
    public:
    void enqueue(){
        if(rear == 99){
            cout<<"Overflow"<<endl;
        }
        else{
            int x;
            cout<<"Enter number to enqueue"<<endl;
            cin>>x;
            if(front == -1){
                front = 0;
            }
            rear++;
            arr[rear] = x;
        }
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"underflow"<<endl;
        }
        else{
            cout<<arr[front]<<endl;
            front++;
            if(front > rear){
                front = -1;
                rear = -1;
            }
        }
    }
    void peek(){
        if(isEmpty()){
            cout<<"underflow"<<endl;
        }
        else{
            cout<<arr[front]<<endl;
        }
    }
    int isEmpty(){
        if(front == -1 || front > rear){
            return 1;
        }
        else{
            return 0;
        }
    }
    int isFull(){
        if(rear >= 99){
            return 1;
        }
        else{
            return 0;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Empty"<<endl;
        }
        else{
            for(int i = front; i <= rear; i++){
                cout<<arr[i]<<endl;
            }
        }
    }
};

int main(){
    queuee q;
    int x = 0;
    while(true){
        cout<<"CHOOSE \n";
        cout<<"1) enqueue \n";
        cout<<"2) dequeue \n";
        cout<<"3) Check for empty \n";
        cout<<"4) Check for full \n";
        cout<<"5) display \n";
        cout<<"6) peek \n";
        cout<<"7) END"<<endl;
        cin>>x;
        switch(x){
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                if(q.isEmpty()){
                    cout<<"Queue is empty"<<endl;
                }
                else{
                    cout<<"Queue is not empty"<<endl;
                }
                break;
            case 4:
                if(q.isFull()){
                    cout<<"Queue is full"<<endl;
                }
                else{
                    cout<<"Queue is not full"<<endl;
                }
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 7:
                return 0;
        }
    }
    return 0;
}

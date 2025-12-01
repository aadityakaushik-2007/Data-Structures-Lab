#include <iostream>
using namespace std;

class stack{
    int arr[100];
    int top = -1;
    public:
    void push(){
        if(top==99){
            cout<<"Overflow"<<endl;
        }
        else{
            int b;
            cout<<"Enter number to push"<<endl;
            cin>>b;
            top++;
            arr[top]=b;
        }
    }
    void pop(){
        if(top<0){
            cout<<"underflow"<<endl;
        }
        else{
            cout<<arr[top];
            top--;
        }
    }
    void peek(){
        if(top<0){
            cout<<"underflow"<<endl;
        }
        else{
            cout<<arr[top];
        }
    }
    int isEmpty(){
        if(top<0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int isFull(){
        if(top>=99){
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
            for(int i = 0; i <= top; i++){
                cout<<arr[i]<<endl;
            }
        }
    }
};

int main(){
    stack s;
    int x = 0;
    while(true){
        cout<<"CHOOSE \n"<<"1) push \n"<<"2) pop \n"<<"3) Check for empty \n"<<"4) check for full \n"<<"5) display \n"<<"6) peek \n"<<"7) END"<<endl;
        cin>>x;
        switch(x){
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.isEmpty();
                break;
            case 4:
                s.isFull();
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
                break;
            case 7:
                return 0;
        }

    }
    return 0;
}
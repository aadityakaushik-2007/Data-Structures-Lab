#include <iostream>
#include <cstring>
using namespace std;

class stack{
    char arr[100];
    int top = -1;
    public:
    void push(int b){
        if(top==99){
            cout<<"Overflow"<<endl;
        }
        else{
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
    string str;
    stack s;
    cout<<"Enter string: "<<endl;
    cin>>str;
    int n = str.length();
    for(int i = 0; i<n; i++){
        s.push(str[i]);
    }
    for(int i = 0; i<n; i++){
        s.pop();
    }

    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

class stack3{
    int arr[100];
    int top;
    public:
    stack3(){
        top = -1;
    }
    void push(int x){
        if(top == 99) return;
        top++;
        arr[top] = x;
    }
    int pop(){
        if(top < 0) return 0;
        int x = arr[top];
        top--;
        return x;
    }
    int isEmpty(){
        return top < 0;
    }
};

int main(){
    char post[100];
    stack3 s;
    cout<<"Enter postfix expression:"<<endl;
    cin>>post;
    int n = strlen(post);
    for(int i=0;i<n;i++){
        char c = post[i];
        if(c>='0' && c<='9'){
            s.push(c - '0');
        }
        else{
            int a = s.pop();
            int b = s.pop();
            int r = 0;
            if(c=='+') r = b + a;
            else if(c=='-') r = b - a;
            else if(c=='*') r = b * a;
            else if(c=='/') r = b / a;
            else if(c=='%') r = b % a;
            s.push(r);
        }
    }
    int ans = s.pop();
    cout<<"Result: "<<ans;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class stackk{
    char arr[100];
    int top=-1;
    public:
    void push(char c){
        if(top<99) arr[++top]=c;
    }
    char pop(){
        if(top<0) return 0;
        return arr[top--];
    }
    char peek(){
        if(top<0) return 0;
        return arr[top];
    }
    int empty(){
        return top<0;
    }
};

int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    if(c=='^') return 3;
    return 0;
}

int main(){
    string in;
    stackk s;
    cin>>in;
    string out="";
    for(int i=0;i<in.size();i++){
        char c=in[i];
        if(isalnum(c)) out+=c;
        else if(c=='(') s.push(c);
        else if(c==')'){
            while(!s.empty() && s.peek()!='(') out+=s.pop();
            if(!s.empty()) s.pop();
        }else{
            while(!s.empty() && prec(s.peek())>=prec(c) && c!='^') out+=s.pop();
            s.push(c);
        }
    }
    while(!s.empty()) out+=s.pop();
    cout<<out;
    return 0;
}

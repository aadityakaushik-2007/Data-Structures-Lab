#include <iostream>
#include <string>
using namespace std;

class stackk{
    char arr[200];
    int top=-1;
    public:
    void push(char c){
        if(top==199) cout<<"overflow";
        else arr[++top]=c;
    }
    char pop(){
        if(top<0) return 0;
        return arr[top--];
    }
    int empty(){
        return top<0;
    }
};

int main(){
    string exp;
    stackk s;
    cin>>exp;
    for(int i=0;i<exp.size();i++){
        char c=exp[i];
        if(c=='('||c=='{'||c=='[') s.push(c);
        else if(c==')'||c=='}'||c==']'){
            char t=s.pop();
            if(!t) { cout<<"Not Balanced"; return 0; }
            if((c==')'&&t!='(')||(c=='}'&&t!='{')||(c==']'&&t!='[')){
                cout<<"Not Balanced";
                return 0;
            }
        }
    }
    if(s.empty()) cout<<"Balanced";
    else cout<<"Not Balanced";
    return 0;
}

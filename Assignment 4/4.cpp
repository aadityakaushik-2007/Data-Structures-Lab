#include <iostream>
#include <string>
using namespace std;

class Queue{
    char arr[1000];
    int front;
    int rear;
public:
    Queue(){
        front = 0;
        rear = -1;
    }
    void enqueue(char x){
        if(rear == 999) return;
        rear++;
        arr[rear] = x;
    }
    char dequeue(){
        if(front > rear) return 0;
        char x = arr[front];
        front++;
        return x;
    }
    int isEmpty(){
        if(front > rear) return 1;
        return 0;
    }
    char peek(){
        if(front > rear) return 0;
        return arr[front];
    }
};

int main(){
    string s;
    cin>>s;
    int freq[26] = {0};
    Queue q;
    int firstOut = 1;
    for(int i = 0; i < (int)s.length(); i++){
        char ch = s[i];
        if(ch >= 'a' && ch <= 'z'){
            freq[ch - 'a']++;
            if(freq[ch - 'a'] == 1) q.enqueue(ch);
            while(!q.isEmpty() && freq[q.peek() - 'a'] > 1){
                q.dequeue();
            }
            if(!firstOut) cout<<" ";
            if(q.isEmpty()) cout<<-1;
            else cout<<q.peek();
            firstOut = 0;
        }
    }
    return 0;
}

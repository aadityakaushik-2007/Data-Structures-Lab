#include <iostream>
using namespace std;
class process {
    public:
    int at;
    int bt;
    int rem;
    int tat;
    int wt;
    bool q;
    process(){

    }
    process(int a, int b){
        at = a;
        bt = b;
        rem = b;
        tat = 0;
        wt = 0;
        q = false;
    }
};
int comp(process p[], int n){
    int s = p[0].rem;
    int x = 0;
    for(int i = 0; i<n; i++){
        int temp = p[i].rem;
        if(s>temp){
            temp = s;
            x = i;
        }
    }
    return x;
}
void sjf(process p[],int n){
    int time = 0;
    int temp = -1;
    bool flag = false;
    while(time != temp){
        for(int i = 0; i<n; i++){
            int temp = p[i].at;
            if (time==temp){
                flag = true;
                p[i].q=true;
                break;
            }
        }
        if(!flag){
            time++;
        }
    }
    


}

int main(){
    process p[4];
    int n = 4;
    for (int i = 0; i<4; i++){
        int x,y;
        cin>>x>>y;
        p[i]=process(x,y);
    }
    return 0;
}
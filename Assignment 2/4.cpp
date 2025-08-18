#include <iostream>
#include <string>
using namespace std;

string conc(string s1,string s2){
    return s1+s2;
}

string rev(string s){
    int n=s.size();
    string rev="";
    for(int i=n-1;i>=0;--i){
        rev+=s[i];
    }
    return rev;
}

string del(string s) {
    string result = "";
    for (char c : s) {
        char ch = tolower(c);
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            result += c;  // keep consonants
        }
    }
    return result;
}

string sort(string s) {
    int n = s.length();
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++){
            if (s[j]>s[j+1]){
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    return s;
}

string low(string s) {
    for (int i=0;i<s.size();i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}
int main() {
    string s1,s2;
    cout << "Enter Strings: ";
    getline(cin,s1);
    getline(cin,s2);
    cout<<"Concatenated Strings : "<< conc(s1,s2)<<endl;
    cout<<"Reversed String: "<<rev(s1)<<endl;
    cout<<"String with deleted Vowels : "<<del(s1)<<endl;
    cout<<"String with sorted letters : "<<sort(s1)<<endl;
    cout<<"String with lowercase letters : "<<low(s1)<<endl;
}
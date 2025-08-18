#include <iostream>
using namespace std;

void linmiss(int arr[], int n){
    bool Mistake=false;
    for(int i=0;i<n-1;++i){
        if(arr[i]!=i+1){
            cout<<"Missing number found by linear search: "<<i+1<<"\n";
            Mistake=true;
            break;
        }
    }
    if(Mistake==0){
        cout<<"Your array was good to go mate ~regards linear search \n";
    }   
}

void binmiss(int arr[],int n){
    int low = 0, high = n - 2;
    int missing = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        }
        else {
            missing = mid + 1;
            high = mid - 1;
        }
    }
    if (missing != -1){
        cout << "Missing number found by binary search: " << missing << "\n";
    }
    else{
        cout << "Your array was good to go mate ~regards binary search \n";
    }
}

int main() {
    int n;
    cout << "Enter total no of elements (including the missing one):  ";
    cin >> n;

    int arr[n-1];
    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n-1; i++)
        cin >> arr[i];

    linmiss(arr,n);
    binmiss(arr,n);
    return 0;
}
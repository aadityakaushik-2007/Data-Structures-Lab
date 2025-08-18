#include <iostream>
using namespace std;

int n;
int s;
void lins(int arr[]);
void bins(int arr[]);
void display(int arr[]);

int main(){
    int array[100];
    cout<<"Enter number of elements: \n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter element no. "<<i+1<<"\n";
        cin>>array[i];
    }
    display(array);
    cout<<"enter the element to be searched \n";
    cin>>s;
    lins(array);
    bins(array);
    return 0; 
}

void display(int arr[]){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\n";
    }
}

void lins(int arr[]){
    for(int i =0;i<n;i++){
        if(arr[i]==s){
            cout<<"Element found at "<<i+1<<"th position \n";
            cout<<"Element found by linear search \n";
            break;
        }
        else{
            continue;
        }

    }
    cout<<"INVALID ELEMENT ENTERED PUTA!! regards~ Linear search \n";
}

void bins(int arr[]){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==s){
            cout<<"Element found at "<<mid+1<<"th position \n";
            cout<<"element found by binary search \n";
            break;
        }
        else if(arr[mid]<s){
            low = mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"INVALID ELEMENT ENTERED PUTA! regards~ Binary search \n";
}

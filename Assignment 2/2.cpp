#include <iostream>
using namespace std;

void display(int arr[]){
    for (int i = 0; i < 7; i++){
        cout<<"Element no "<<i+1<<": "<<arr[i]<<"\n";
    }
}

 int main(){
    int arr[7]={64,34,25,12,22,11,90};
    cout<<"Before sorting: \n";
    display(arr);
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6 - i; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout<<"After sorting: \n";
    display(arr);
 }
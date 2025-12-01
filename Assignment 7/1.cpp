#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int t=a; a=b; b=t;
}

void selection(int a[],int n){
    for(int i=0;i<n;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[m]) m=j;
        }
        swap(a[i],a[m]);
    }
}

void insertion(int a[],int n){
    for(int i=1;i<n;i++){
        int t=a[i],j=i-1;
        while(j>=0 && a[j]>t){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
}

void bubble(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}

void mergeArr(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int x[100],y[100];
    for(int i=0;i<n1;i++) x[i]=a[l+i];
    for(int j=0;j<n2;j++) y[j]=a[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(x[i]<y[j]) a[k++]=x[i++];
        else a[k++]=y[j++];
    }
    while(i<n1) a[k++]=x[i++];
    while(j<n2) a[k++]=y[j++];
}

void mergeSort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        mergeArr(a,l,m,r);
    }
}

int partition(int a[],int l,int r){
    int p=a[r],i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<p){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(int a[],int l,int r){
    if(l<r){
        int p=partition(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    int a[100],b[100];
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ch;
    while(true){
        for(int i=0;i<n;i++) b[i]=a[i];
        cout<<"CHOOSE\n1) Selection Sort\n2) Insertion Sort\n3) Bubble Sort\n4) Merge Sort\n5) Quick Sort\n6) Exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                selection(b,n);
                print(b,n);
                break;
            case 2:
                insertion(b,n);
                print(b,n);
                break;
            case 3:
                bubble(b,n);
                print(b,n);
                break;
            case 4:
                mergeSort(b,0,n-1);
                print(b,n);
                break;
            case 5:
                quickSort(b,0,n-1);
                print(b,n);
                break;
            case 6:
                return 0;
        }
    }
    return 0;
}

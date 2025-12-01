#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void insert(int a[], int& n, int value) {
    a[n] = value;
    int i = n;
    n++;
    while (i > 0 && a[(i-1)/2] < a[i]) {
        swap(a[i], a[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extractMax(int a[], int& n) {
    int root = a[0];
    a[0] = a[n-1];
    n--;
    heapify(a, n, 0);
    return root;
}

int main() {
    int pq[100];
    int n = 0;

    insert(pq, n, 10);
    insert(pq, n, 4);
    insert(pq, n, 15);
    insert(pq, n, 20);
    insert(pq, n, 1);

    cout << "Priority queue (max-heap): ";
    while (n > 0) {
        cout << extractMax(pq, n) << " ";
    }

    return 0;
}
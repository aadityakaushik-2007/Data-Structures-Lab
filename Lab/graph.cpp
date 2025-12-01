#include <iostream>
using namespace std;

void linkedl(int n){
    int** arr = new int*[n];
}
int main() {
    int v, e;
    cout << "Enter number of vertices";
    cin >> V;
    cout << "Enter number of edges";
    cin >> E;

    cout << "Enter edges (u v):";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1][v-1] = 1;
        adj[v-1][u-1] = 1;
    }
    dispMatrix(adj, V);
    return 0;
}
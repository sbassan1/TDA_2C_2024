#include <iostream>
#include <vector>
using namespace std;

void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s, int cont, int& conjA) {
    visited[s] = true;

    if (cont % 2 != 0) { // Cuento los vertices impares del DFS.
        conjA++;
    }

    for (int i : adj[s]) {
        if (!visited[i]) {
            DFSRec(adj, visited, i, cont + 1, conjA);
        }
    }
}

void DFS(vector<vector<int>> &adj, int s, int& conjA) {
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s, 0, conjA);
}

int main() {
    int t;  // número de vértices
    cin >> t;

    vector<vector<int>> adj(t + 1);

    for (int i = 0; i < t - 1; i++) { // t-1 aristas
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    int conjA = 0; // nro de elementos de un conjunto de vertices 'a'
    int s = 1; // Vertice raiz para el DFS
    DFS(adj, s, conjA);

    cout << (conjA *  (t - conjA)) - (t-1) << endl; // (Cant de aristas bipart completo) - (aristas que tenemos)

    return 0;
}

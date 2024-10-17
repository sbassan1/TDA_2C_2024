#include <iostream>
#include <vector>
using namespace std;

void DFSRec(const vector<vector<long long>> &adj, vector<bool> &visited, long long s, long long cont, long long& conjA) {
    visited[s] = true;

    if (cont % 2 == 0) { // Contar vértices de nivel par en DFS (conjunto A)
        conjA++;
    }

    for (long long i : adj[s]) {
        if (!visited[i]) {
            DFSRec(adj, visited, i, cont + 1, conjA);
        }
    }
}

void DFS(const vector<vector<long long>> &adj, long long s, long long& conjA) {
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s, 0, conjA);
}

int main() {
    long long t;  // número de vértices
    cin >> t;

    vector<vector<long long>> adj(t + 1);

    for (long long i = 0; i < t - 1; i++) { // t-1 aristas
        long long a, b;
        cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    long long conjA = 0; // nro de elementos del conjunto A
    long long s = 1;
    DFS(adj, s, conjA);

    long long conjB = t - conjA;

    long long cantTotalAristGrafBipart = conjA * conjB;

    long long aristActuales = t - 1;

    cout << cantTotalAristGrafBipart - aristActuales << endl;

    return 0;
}

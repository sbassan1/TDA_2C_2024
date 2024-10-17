#include <iostream>
#include <vector>
using namespace std;

void DFSRec(const vector<vector<int>> &adj, vector<bool> &visited, int s, int cont, int& conjA) {
    visited[s] = true;

    if (cont % 2 == 0) { // Contar vértices de nivel par en DFS (conjunto A)
        conjA++;
    }

    for (int i : adj[s]) {
        if (!visited[i]) {
            DFSRec(adj, visited, i, cont + 1, conjA);
        }
    }
}

void DFS(const vector<vector<int>> &adj, int s, int& conjA) {
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s, 0, conjA);
}

int main() {
    int t;  // número de vértices
    cin >> t;

    vector<vector<int>> adj(t + 1);

    for (int i = 0; i < t - 1; i++) { // t-1 aristas (en un árbol siempre hay t-1 aristas)
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    int conjA = 0; // nro de elementos del conjunto A
    int s = 1;
    DFS(adj, s, conjA);

    int conjB = t - conjA; // El otro conjunto es el resto de los vértices
    int cantTotalAristGrafBipart = conjA * conjB;
    int aristActuales = t - 1;  // El árbol tiene exactamente t-1 aristas

    cout << cantTotalAristGrafBipart - aristActuales << endl;

    return 0;
}

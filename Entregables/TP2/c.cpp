    #include <iostream>
    #include <vector>
    #include <queue>
    using namespace std;

    int INF = 2e5;

    void bfsDistancias(const vector<vector<int>>& adj, int n, int source) {
        
        vector<int> dist(n, INF); // vector de distancias desde nodo 0;
        dist[source] = 0;
        
        queue<int> q;
        q.push(source);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < n; ++i) { // Distancias de aulas entre M_i a M_n desde aula 0
            cout << dist[i] << " ";
        }
    }


    int main() {
        int t;  // número de vértices
        cin >> t;

        vector<vector<int>> adj(t); // Se que no es necesario usar los pesos en este caso.

        for (int i = 0; i < t - 1; i++) { // Agregamos todas las aristas entre aulas
            adj[i].push_back(i+1); 
            adj[i+1].push_back(i);

            int c;
            cin >> c;
            c--;
            if (c != i) {
                adj[i].push_back(c);
            }
        }

        bfsDistancias(adj, t, 0);

        return 0;
    }

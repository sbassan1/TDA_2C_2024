#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int a, b, w; // vértices a, b y su peso
    int id;
};




int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m); // Usamos un vector de Edge
    
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].id = i; // Asigna el id a cada arista
    }
    
    sort(edges.begin(), edges.end(), [](Edge &e1, Edge &e2) {
        return e1.w < e2.w;
    });
    
    for (const auto &edge : edges) {
        cout << edge.a << " " << edge.b << " " << edge.w << endl;
    }

    vector<string> result(m, "none");





    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int INF = 1e9;

int N, P; // N cantidad de canciones y P es la cantidad de minutos max de CD

vector<int> p; // Cantidad de minutos de canciones del CD

int CD(int i, int k) {
    if (i == N) // Si llego a la hoja del arbol de deciciones
        return (k < 0 ? -INF : 0); // Si la cantidad de minutos restantes es menor a 0 entonces devolvemos -INF, Si no 0
    else
        return max(CD(i+1, k - p[i]) + p[i], CD(i+1, k));
}

int main() {
    cin >> N >> P;

    p.resize(N, -1);
    for (int i=0; i<N; i++) cin >> p[i];

    cout << CD(0, P) << endl;

    return 0;
}

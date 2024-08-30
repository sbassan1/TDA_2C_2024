#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/* 
1
5 3
1
2
8
4
9 
 */

// Necesito mantener calculado la distancia minima entre las vacas entre cubiculos de cada permutacion y devolverla la mayor

const int INF = 2e5;

unordered_map<long long, int> mem;
int mejorDistanciaGlobal = -INF;

long long codificarClave(int vacasRestantes, int i, int ultimaPosicion, int distanciaMinima) {
    return (((long long)vacasRestantes) << 40) | (((long long)i) << 30) | (((long long)ultimaPosicion) << 15) | distanciaMinima;
}

int distanciaMinimaMaxima(vector<int>& cubiculos, int vacasRestantes, int i, int ultimaPosicion, int distanciaMinima) {

    if (distanciaMinima <= mejorDistanciaGlobal) { // No puede mejorar la mejor solución actual
        return -INF;  
    }

    if (vacasRestantes > cubiculos.size() - i) {   // No quedan espacios suficientes para mas vacas
        return -INF;
    }

    if (vacasRestantes == 0) {              // Me fijo si la solucion actual es mejor que la maxima encontrada hasta el momento
        mejorDistanciaGlobal = max(mejorDistanciaGlobal, distanciaMinima);
        return distanciaMinima;
    }

    if (i == cubiculos.size()) {    // En el caso de quedarme sin espacios y hay vacas
        return -INF;
    }

    long long key = codificarClave(vacasRestantes, i, ultimaPosicion, distanciaMinima); // Consigo una key para el map

    if (mem.find(key) != mem.end()) return mem[key];

    if (ultimaPosicion != -1 && cubiculos[i] - ultimaPosicion <= mejorDistanciaGlobal) {
        return -INF;
    }

    int noAgregamosVaca = distanciaMinimaMaxima(cubiculos, vacasRestantes, i + 1, ultimaPosicion, distanciaMinima);

    int nuevaDistanciaMinima = distanciaMinima;

    if (ultimaPosicion != -1) {
        nuevaDistanciaMinima = min(distanciaMinima, cubiculos[i] - ultimaPosicion);
    }
    int agregamosVaca = distanciaMinimaMaxima(cubiculos, vacasRestantes - 1, i + 1, cubiculos[i], nuevaDistanciaMinima);

    return mem[key] = max(agregamosVaca, noAgregamosVaca);
}

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n, c;
        cin >> n >> c;

        vector<int> cubiculos(n);
        for (int i = 0; i < n; i++) {
            cin >> cubiculos[i];
        }

        sort(cubiculos.begin(), cubiculos.end());

        mem.clear();
        mejorDistanciaGlobal = -INF;

        int mejorDistanciaMinima = distanciaMinimaMaxima(cubiculos, c - 1, 1, cubiculos[0], INF);
        cout << mejorDistanciaMinima << endl;

        t--;
    }

    return 0;
}

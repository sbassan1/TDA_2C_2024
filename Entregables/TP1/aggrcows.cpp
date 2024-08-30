#include <iostream>
#include <vector>
#include <algorithm>

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

int distanciaMinimaMaxima(vector<int>& cubiculos, int vacasRestantes, int i, int ultimaPosicion, int distanciaMinima) {
    if (vacasRestantes == 0) {
        return distanciaMinima;  // Todas las vacas han sido colocadas, devolver la distancia mínima calculada
    }

    if (i == cubiculos.size()) {
        return -INT_MAX;  // No se pueden colocar todas las vacas
    }

    int noAgregamosVaca = distanciaMinimaMaxima(cubiculos, vacasRestantes, i + 1, ultimaPosicion, distanciaMinima);

    int nuevaDistanciaMinima = distanciaMinima; // Nosotros comenzamos sin agregar vacas con distancia minima en INT MAX

    if (ultimaPosicion != -1) {  // Si no es la primera vaca
        nuevaDistanciaMinima = min(distanciaMinima, cubiculos[i] - ultimaPosicion); // Verificamos que la distancia entre la nueva vaca es menor
    }
    int agregamosVaca = distanciaMinimaMaxima(cubiculos, vacasRestantes - 1, i + 1, cubiculos[i], nuevaDistanciaMinima); 

    return max(noAgregamosVaca, agregamosVaca);
}

int main() {
    int t;  // T casos
    cin >> t;

    while (t--) {
        int n, c;  // N cubículos, C vacas
        cin >> n >> c;

        vector<int> cubiculos(n);
        for (int i = 0; i < n; i++) {
            cin >> cubiculos[i];
        }

        sort(cubiculos.begin(), cubiculos.end()); // Acá sorteo la lista de posiciones para tenerlas de menor a mayor

        int mejorDistanciaMinima = distanciaMinimaMaxima(cubiculos, c, 0, -1, INT_MAX);
        cout << mejorDistanciaMinima << endl;
    }

    return 0;
}

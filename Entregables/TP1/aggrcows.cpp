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

const int INF = 2e5;

bool esDistanciaValida(vector<int> cubiculos, int cantCubiculos, int cantVacas, int distMedia){

    int posicionActual = cubiculos[0]; // Donde vamos guardando vacas

    int vacas = 1; // Cantidad de vacas que pusimos para verificar

    for( int i = 1 ; i < cantCubiculos ; i++){ // recorremos todas las posiciones del cubiculo

        if (cubiculos[i] - posicionActual >= distMedia){ // Si esto vale podemos agregar una vaca con la distanciaMedia
            vacas++;
            posicionActual = cubiculos[i];
        }

        if (vacas == cantVacas) return true; // Si pusimos todas las vacas esta distancia es la optima 

    }

    return false; // Si no llenamos las posiciones con todas las vacas entonces no es la solucion optima
}

int vacasEnojadas(vector<int> cubiculos, int cantCubiculos, int cantVacas){

    int izq = 1;
    int der = cubiculos[cantCubiculos-1];

    int res = -1; // Si no hay una solucion (hay mas vacas que cantCubiculos)

    if (cantCubiculos < cantVacas) {
        return -1;
    }

    while( izq < der){
        int distMedia = (izq + der) / 2; // Distancia media entre los dos puntos

        if ( esDistanciaValida(cubiculos, cantCubiculos, cantVacas, distMedia)){
            res = max(res, distMedia);
            izq = distMedia + 1; // Actualizamos la posicion 
        }
        else{
            der = distMedia;
        }
    } 
    return res;
}


int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n, c; // N cantidad de cubiculos, C cantidad de vacas
        cin >> n >> c;

        vector<int> cubiculos(n);

        for (int i = 0; i < n; i++) { // Guardamos distancias de cubiculos.
            cin >> cubiculos[i];
        }

        sort(cubiculos.begin(), cubiculos.end()); // O(n log(n)) para ordenar elementos primero

        cout << vacasEnojadas(cubiculos, n , c) << endl;

        t--;
    }

    return 0;
}

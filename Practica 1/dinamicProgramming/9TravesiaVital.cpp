#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int INF = 2e5;

/* 
Tengo una matriz de nxn que necesito atravesar desde el extremo superior derecho (0,0)
hasta el extremo inferior izquierdo (n,n), cuando paso por un numero en la matriz pierdo 
o gano puntos, estos los voy sumando o restando hasta llegar a (n,n), tambien solo puedo 
moverme un casillero abajo o uno a la derecha para llegar a (n,n). La idea es intentar
maximizar la cantidad de puntos desde (0,0) hasta (nxn).
 */

int TravesiaVital(vector<vector<int>>& terreno, int i, int j) {
    int n = terreno.size();   
    int m = terreno[0].size();

    if (i == (n - 1) && j == (m - 1)) {
        return terreno[i][j];
    }

    if (i >= n || j >= m) {
        return INF;
    }

    int movimientoDerecha = TravesiaVital(terreno, i, j + 1) + terreno[i][j];
    int movimientoAbajo = TravesiaVital(terreno, i + 1, j) + terreno[i][j];

    if(movimientoDerecha < movimientoAbajo)
}
int main() {

    int m = 3; // cantidad de filas
    int n = 3; // cantidad de columnas

    vector<vector<int>> terreno{{-2,-3,3},{-5,-10,1},{10,30,-5}}; 
    
    int vida_final = TravesiaVital(terreno, 0, 0);

    cout << "Maxima ganancia posible: " << vida_final << endl;

    return 0;
}
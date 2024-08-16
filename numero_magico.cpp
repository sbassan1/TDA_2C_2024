#include <iostream>

using namespace std;

int N;

bool esCuadradoMagicoValido(vector<vector<int>> &cuadrado,int n,int numeroMagico){

        int sumatoriaFila = cuadrado[i][0] + cuadrado[i][1] + cuadrado[i][2];
        int sumatoriaColumna = cuadrado[0][j] + cuadrado[1][j] + cuadrado[2][j];
        int sumatoriaDiagonalIzq = cuadrado[0][0] + cuadrado[1][1] + cuadrado[2][2];
        int sumatoriaDiagonalDer = cuadrado[0][2] + cuadrado[1][1] + cuadrado[2][0];

}


void cantCuadradosValidos(vector<vector<int>> &cuadrado, set<int> &numerosDisponibles, int i, int j, int n, int numeroMagico, int &numeroPermutacionesValidas){

    if (i == n){
        if (esCuadradoMagicoValido(cuadrado,n,numeroMagico)){
            numeroPermutacionesValidas++;
        }
        return;
    }

    if(j == n){
        cantCuadradosValidos(cuadrado, numerosDisponibles, i+1, 0, n, numeroMagico, numeroPermutacionesValidas);
        return
    }

    for (auto num : numerosDisponibles) {
        cuadrado[i][j] = num;
        numerosDisponibles.erase(num);

        int sumatoriaFila = cuadrado[i][0] + cuadrado[i][1] + cuadrado[i][2];
        int sumatoriaColumna = cuadrado[0][j] + cuadrado[1][j] + cuadrado[2][j];
        int sumatoriaDiagonalIzq = cuadrado[0][0] + cuadrado[1][1] + cuadrado[2][2];
        int sumatoriaDiagonalDer = cuadrado[0][2] + cuadrado[1][1] + cuadrado[2][0];

        if( sumatoriaFila <= numeroMagico && sumatoriaColumna <= numeroMagico && sumatoriaDiagonalIzq <= numeroMagico && sumatoriaDiagonalDer <= numeroMagico){
            cantCuadradosValidos(cuadrado, numerosDisponibles, i, j+1, n, numeroMagico, numeroPermutacionesValidas);
        }
        numerosDisponibles.insert(num);
        cuadrado[i][j] = 0;
    }



}

int main() {
    cin >> N;
 
    set<int> numerosDisponibles; // Aca tenemos los conjunto de numeros

    for(int i = 0 ; i < N*2; i++){
        numerosDisponibles.insert(i); // Llenamos el conjunto de numeros
    }

    vector<vector<int>> cuadrado(N,vector<int>(N,0)); // Inicializo el cuadrado de NxN con ceros

    int numeroMagico = ((N^3) + N) / 2; // Aca tenemos el numero magico que tiene que sumar todas las filas y columnas

    int numeroPermutacionesValidas = 0; // Aca vamos a guardar las permutaciones que son validas  

    cantCuadradosValidos(cuadrado, numerosDisponibles, 0,0,N,numeroMagico, numeroPermutacionesValidas);


    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int calcularSumaFinal(vector<vector<int>>& cuadrado, int k, vector<int> sol_parcial) {
    int suma = 0;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            suma += cuadrado[sol_parcial[i] - 1][sol_parcial[j] - 1];
        }
    }
    return suma;
}

void maxSubconjunto(vector<vector<int>>& cuadrado, int k, int n, vector<int>& sol_parcial, 
                    vector<int>& final, int& sumaMaxima, int i) {

    if (sol_parcial.size() == k) {
        int sumaSolucion = calcularSumaFinal(cuadrado, k, sol_parcial);
        if (sumaSolucion > sumaMaxima) {
            final = sol_parcial;
            sumaMaxima = sumaSolucion;
        }
        return;
    }

    if (i == n) {
        return;
    }

    sol_parcial.push_back(i + 1);
    maxSubconjunto(cuadrado, k, n, sol_parcial, final, sumaMaxima, i + 1);
    sol_parcial.pop_back();
    maxSubconjunto(cuadrado, k, n, sol_parcial, final, sumaMaxima, i + 1);
}

int main() {
    int n = 4;
    int k = 3;

    vector<vector<int>> cuadrado{{0,10,10,1},{10,0,5,2},{10,5,0,1},{1,2,1,0}};
    vector<int> sol_parcial{};
    vector<int> final{};
    int sumaMaxima = 0;

    maxSubconjunto(cuadrado, k, n, sol_parcial, final, sumaMaxima, 0);

    for (int i = 0; i < final.size(); i++) {
        cout << final[i] << ",";
    }
}

#include <iostream>
#include <vector>
#include <algorithm>

/*
Razonamiento: 

Tengo que conseguir el maximo subconjunto ascendiente (Numeros Negros) y descendiente 
(Numeros Blancos) de una secuencia representada por un vector de ints de tal modo que 
maximize la cantidad de elementos negros y blancos (Use la mayor cantidad de numeros en total).

Tengo que fijarme en los numeros de la secuencia:

- Si el numero actual es mayor al ultimo numero negro entonces es candidato a ser
el siguiente numero negro.
- Si el numero actual es menor al ultimo numero blanco entonces es candidato a ser
el siguiente numero blanco.
- Quiero maximizar la cantidad de numeros negros y blancos (los numeros no pueden ser
negros y blancos a la vez, si elijo uno entonces el numero en ese espacio solo puede
ser parte de un color). 

Lo que puedo hacer en la recursion entonces es:

- Agregar el numero actual a negros
- Agregar el numero actual a blancos
- No agregar el numero actual a ninguno.

 */

using namespace std;

int INF = 99999999;

int blackOrWhite(vector<int>& secuenciaNumeros, int i, int n, int ultimoBlanco, int ultimoNegro, int maxActual, vector<vector<vector<int>>>& memo) {
    if (i == n) return 0;

    int ajustadoBlanco = ultimoBlanco + 1;
    int ajustadoNegro = ultimoNegro + 1;

    if (memo[i][ajustadoBlanco][ajustadoNegro] != -1) return memo[i][ajustadoBlanco][ajustadoNegro];

    int numRestantes = n - i;
    int maxDecisionActual = maxActual + numRestantes;
    if (memo[i][ajustadoBlanco][ajustadoNegro] >= maxDecisionActual) {
        return 0;
    }

    int agregoNegro = 0, agregoBlanco = 0, agregoNinguno;
    agregoNinguno = blackOrWhite(secuenciaNumeros, i+1, n, ultimoBlanco, ultimoNegro, maxActual, memo);

    if (ultimoNegro == -1 || secuenciaNumeros[i] > secuenciaNumeros[ultimoNegro]) {
        agregoNegro = blackOrWhite(secuenciaNumeros, i+1, n, ultimoBlanco, i, maxActual + 1, memo) + 1;
    }

    if (ultimoBlanco == -1 || secuenciaNumeros[i] < secuenciaNumeros[ultimoBlanco]) {
        agregoBlanco = blackOrWhite(secuenciaNumeros, i+1, n, i, ultimoNegro, maxActual + 1, memo) + 1;
    }

    memo[i][ajustadoBlanco][ajustadoNegro] = max({agregoNegro, agregoBlanco, agregoNinguno});
    return memo[i][ajustadoBlanco][ajustadoNegro];
}

int main() {
    while (true) {
        int n; // Número de números
        cin >> n;

        if (n == -1) break;

        vector<int> secuenciaNumeros(n);
        for (int i = 0; i < n; i++) {
            cin >> secuenciaNumeros[i];
        }

        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n+1, vector<int>(n+1, -1)));        
        int maxActual = 0;

        cout << n - blackOrWhite(secuenciaNumeros, 0, n, -1, -1, maxActual, memo) << endl;
    }
    return 0;
}

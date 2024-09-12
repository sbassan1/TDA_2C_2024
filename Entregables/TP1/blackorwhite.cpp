#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>
#include <map>

using namespace std;

/*
Razonamiento: 

Tengo que conseguir el maximo subconjunto ascendiente (Numeros Negros) y decendiente 
(Numberos Blancos) de una secuencia representada por un vector de ints de tal modo que 
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

int INF = 99999999;

map<tuple<int, int, int>, int> memo;

int blackOrWhite(vector<int>& secuenciaNumeros, int i, int n, int ultimoBlanco, int ultimoNegro){
    if (i == n) return 0;

    tuple<int, int, int> decisionActual = make_tuple(i, ultimoBlanco, ultimoNegro);

    if (memo.find(decisionActual) != memo.end()) return memo[decisionActual];

    int agregoNegro = 0, agregoBlanco = 0, agregoNinguno;


    if (secuenciaNumeros[i] > ultimoNegro) {
        agregoNegro = blackOrWhite(secuenciaNumeros, i+1, n, ultimoBlanco, secuenciaNumeros[i]) + 1;
    }

    if (secuenciaNumeros[i] < ultimoBlanco) {
        agregoBlanco = blackOrWhite(secuenciaNumeros, i+1, n, secuenciaNumeros[i], ultimoNegro) + 1;
    }

    agregoNinguno = blackOrWhite(secuenciaNumeros, i+1, n, ultimoBlanco, ultimoNegro);

    memo[decisionActual] = max({agregoNegro, agregoBlanco, agregoNinguno});
    return memo[decisionActual];


}


int main(){
    
    while (true) {
        int n; // Numero de numeros
        cin >> n;

        if (n == -1) break;

        vector<int> secuenciaNumeros(n);

        for (int i = 0; i < n; i++) {
            cin >> secuenciaNumeros[i];
        }

        memo.clear();

        cout << n - blackOrWhite(secuenciaNumeros, 0, n, INF, -INF) << endl;

    }
    return 0;
}

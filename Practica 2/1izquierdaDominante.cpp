#include <iostream>
#include <vector>
using namespace std;

bool esMasIzquierda(vector<int>& numeros, int min, int max) {

    if (min >= max) {
        return true;
    }
    int mid = (min + max) / 2;

    int sum1 = 0;
    for (int i = min; i <= mid; i++) {
        sum1 += numeros[i];
    }

    int sum2 = 0;
    for (int i = mid + 1; i <= max; i++) {
        sum2 += numeros[i];
    }
    if (sum1 < sum2) {
        return false;
    }

    return esMasIzquierda(numeros, min, mid) && esMasIzquierda(numeros, mid + 1, max);
}

/* 
T(n) = a T ( n / b ) + O ( n ^ d)

Donde:

a = 2; num subproblema
b = 2; divido el tamaño en n/2
d = 1; Como mucho tardo O(n) en verificar si una mitad es mas grande que otra.

log {b} (a) = d

log {2} (2) = 1

d = 1

Complejidad : O( n^d log n) == O(n log n)

 */

int main() {

    vector<int> numeros = {8, 6, 7, 4, 5, 1, 3, 2};


    if (esMasIzquierda(numeros, 0, numeros.size() - 1)) {
        cout << "La mitad izquierda es mayor en todas las divisiones." << endl;
    } else {
        cout << "La mitad izquierda no es mayor en alguna división." << endl;
    }

    return 0;
}

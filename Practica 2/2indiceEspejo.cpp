#include <iostream>
#include <vector>
using namespace std;


bool indiceEspejo(vector<int>& numeros, int min, int max) {
    if (min > max) return false;

    int mid = (max + min) / 2; 

    if (numeros[mid] == mid + 1) return true; 

    if (numeros[mid] > mid + 1) {
        return indiceEspejo(numeros, min, mid - 1);
    } 
    else {
        return indiceEspejo(numeros, mid + 1, max);
    }
}


/* 
T(n) = a T ( n / b ) + O ( n ^ d)

Donde:

a = 1; num subproblema
b = 2; divido el tamaño en n/2
d = 0; Como mucho tardo O(1) en verificar si el numero es el idx.

log {b} (a) = d

log {2} (1) = 0

d = 0

0 = 0 ==> O(n log n)

 */

int main() {

    //vector<int> numeros = {-4, -1, 2, 4, 7};
    vector<int> numeros = {-4, -1, 2, 4, 7};

    cout << indiceEspejo(numeros, 0, numeros.size());

    return 0;
}

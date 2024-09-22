#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros({6, 23, 88, 93, 58, 22, 1, 52, 17, 95, 87, 31, 79, 81, 33, 88, 55, 24, 100, 13, 47, 58, 23, 81, 78, 45, 38, 10, 38, 21, 89, 36, 30, 14, 44, 69, 90, 42, 50, 87});

    make_heap(numeros.begin(), numeros.end()); // O( n log n)

    int k;
    cout << "Ingresa el valor de k: ";
    cin >> k;

    int sum = 0;

    for (int i = 0; i < k; i++) { // O(k)
        pop_heap(numeros.begin(), numeros.end() - i);
        cout << numeros[numeros.size() - 1 - i] << " "; 
        sum += numeros[numeros.size() - 1 - i];
    }

    cout << endl << "La suma de los " << k << " mayores elementos es: " << sum << endl;

    return 0;
}


/* 
Para llegar a n log k puedo crear un max heap de tamaño k en los cuales voy agregando
de a k elementos.
 */
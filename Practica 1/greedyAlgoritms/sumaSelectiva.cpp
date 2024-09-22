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

b)
Crear un heap y agregar todos los elementos a este O(n log n), tambien se puede con un
merge sort.

c)
Creamos un heap de k elementos
Iteramos por todo el vector agregando y sacando elementos, con esto llegamos O (n log k)
Sumamos el tope k veces sumandolo a la sum.
 */


/* 
Tenemos dos conjuntos de personas y queremos armar la maxima cantidad de parejas de bailarines.
Los numeros de los dos conjuntos representan la habilidad de cada una de las personas. Para
armar parejas estas no deben tener mas de 1 numero de habilidad de diferencia.

- Los numeros de habilidades estan en orden ascendiente
- Tengo que buscar : el numero a comparar (+-1)
 
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> conj1({1,1,1,1,1});
    vector<int> conj2({1,2,3});
    
    int i = 0, j = 0;
    int cont = 0;
    
    while (i < conj1.size() && j < conj2.size()) {
        if (abs(conj1[i] - conj2[j]) <= 1) {
            cont++;
            i++;
            j++;
        } else if (conj1[i] < conj2[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << cont << endl;

    return 0;
}

/* 
b)

Este algorimo recorre elemento por elemento de cada uno hasta que uno termina, de tal
modo que es O(n) donde n es el tamaño del conjunto mas grande entre los 2.

La complejidad espacial del problema es O(1) ya que guardamos ambos indices y un contador  
 */


/* 
c)

Tenemos dos conjuntos de numeros, los cuales vamos a iterar con dos indices, en el algoritmo
si cualquiera de los dos indices llega a su fin, entonces el ciclo corta y el algoritmo devuelve
la cantidad del contador.

Si ambos conjuntos estan en orden ascendiente entonces puedo ir buscando si el numero tiene
una pareja en el otro iterando, en el caso de sobrepasar con -+1 vamos al siguiente numero
en el primer conjunto. Esto continua hasta que uno de los dos conjuntos ya no tiene mas numeros
a comparar.
 */



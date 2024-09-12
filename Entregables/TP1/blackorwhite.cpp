#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>

using namespace std;

/* 
Tengo que conseguir el maximo subconjunto ascendiente (Numeros Negros) y decendiente 
(Numberos Blancos) de un vector de ints de forma recursiva. (No llegue a resolverlo 
con la forma binaria de las formulas) de tal modo que maximice la cantidad de 
elementos en ambos y minimize la cantidad de ints sin usar.

Tengo que fijarme en los numeros blancos y negros. 

- Si el numero actual es mayor al ultimo numero negro entonces es candidato a ser
el siguiente numero negro.
- Si el numero actual es menor al ultimo numero blanco entonces es candidato a ser
el siguiente numero blanco.
- Quiero maximizar la cantidad de numeros negros y blancos (los numeros no pueden ser
negros y blancos a la vez, si elijo uno entonces el numero en ese espacio solo puede
ser parte de un color). 


Puedo:

- Agregar el numero actual a negros
- Agregar el numero actual a blancos
- No agregar el numero actual a ninguno.

Ver cual de los tres es la opcion que te de el maximo numero de elementos pintados.

 */

int blackOrWhite(vector<int> &listaNumeros, int i, int ultimoBlanco, int ultimoNegro, ){

    if (i == n) return 0;  
    
      
}

int main(){
    
    
    while (true) {

        int n; // Numero de numeros
        cin >> n;

        if (n == -1) break;

        vector<int> listaNumeros(n);

        for (int i = 0; i < n; i++) {
            cin >> listaNumeros[i];
        }

        cout << "Ingresaste el vector: {";
        for(int i = 0; i < n; i++){
            (i < n - 1)? cout << listaNumeros[i] << ", " : cout << listaNumeros[i];
        }
        cout << "}" << endl;


    }
    return 0;
}

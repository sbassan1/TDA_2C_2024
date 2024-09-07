#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>

using namespace std;


int blackOrWhite(vector<int> &listaNumeros, int i, int numActual, vector<bool> solParcial, int &max, int &maxActual){


    if (i == n){

        max

    }


    int agregoNumero =   blackOrWhite(listaNumeros, i+1, listaNumeros[i], solParcial, max + 1);
    int noAgregoNumero = blackOrWhite(listaNumeros, i+1, numActual, solParcial, max);

    if (numActual > listaNumeros[i]){ // Si por ejemplo tengo 6 y desp 5 no puedo agregar el 5 
        noagregoNumero()
    }else{

        solParcial[i] = true;
        agregoNumero(listaNumeros, i+1,)
        solParcial[i] = false;
        noagrego(listaNumeros, i+1,)

        noagrego()
    }
    
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

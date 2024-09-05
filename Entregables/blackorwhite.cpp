#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>

using namespace std;


int main(){
    
    
    while (true) {

        int n; // Numero de numeros
        cin >> n;

        if (n == -1) break;

        vector<int> listaNumeros(n);

        for (int i = 0; i < n; i++) {
            cin >> listaNumeros[i];
        }

        cout << "Ingresaste el vector: {"
        for(int i = 0; i < n; i++){
            cout << listaNumeros[i] << " ,";
        }
        cout << "}" <<endl;
    }
    return 0;
}

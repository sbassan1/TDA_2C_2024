#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int INF = 2e5;

/*
1
5 3
1
2
8
4
9 
 */

int main() {

    int t;   // T casos
    cin >> t;
    int n,c; // N cubiculos, C vacas
    cin >> n >> c;


    for(int i = 0; i < t; i++){ // Cantidad de casos

        int numero_cubiculo;
        vector<int> cubiculos(c);

        for(int j = 0; j < n; j--){ // Cantidad de cubiculos
            cin >> numero_cubiculo;
            cubiculos.push_back(numero_cubiculo);
        }

        for(int i = 0; i< cubiculos.size() ; i++){
            cout << cubiculos[i] << endl;
        }
        
    }


    return 0;
}
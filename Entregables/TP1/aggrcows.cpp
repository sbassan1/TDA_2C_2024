#include <iostream>
#include <vector>

using namespace std;

/* 
1
5 3
1
2
8
4
9 
 */
int cantVacas( vector<int> &cubiculos, int i, int &distaciaMinimaMaxima, )


int main() {

    int t;   // T casos
    cin >> t;

    for(int i = 0; i < t; i++){ // Hago loop por los casos

        int n, c; // N cubiculos, C vacas
        cin >> n >> c;

        vector<int> cubiculos(n);

        for(int j = 0; j < n; j++){ // Cantidad de cubiculos
            cin >> cubiculos[j];
        }

        cout << endl << "Vector Actual: ";
        for(int x = 0; x < n ; x++){
            cout << cubiculos[x] << " ";
        }
        cout << endl;
    }

    return 0;
}

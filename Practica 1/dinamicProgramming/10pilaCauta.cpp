#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pilaCauta(vector<tuples<int,int>> cajas, int n, int i, int soporteActual, int )

int main() {
    int n = 5; // cantidad de cajas
    vector<tuples<int,int>> cajas{{19,15},{7,13},{5,7},{6,8},{1,2}}; // Donde las tuplas (int,int) representan peso,soporte

    sort(v.begin(), v.end(), [](const tuple<int, int>& a, const tuple<int, int>& b) {
        return get<0>(a) < get<0>(b);
    }); // Ahora tengo las cajas organizadas por peso.



    cout << "Maxima cant cajas: " << pilasCauta(pesosOrdenados, soportesOrdenados, n, 0, 0, INT_MAX) << endl;

    return 0;
}

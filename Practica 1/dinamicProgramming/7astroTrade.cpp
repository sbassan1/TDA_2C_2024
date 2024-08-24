#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 2e5;


int main() {
/*     int costo = 14;  // Costo del producto
    vector<int> billetera{2, 3, 5, 10, 20, 20};  // Cantidad de billetes y su denominacion */

    int costo = 9;  // Costo del producto
    vector<int> billetera{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10};  // Cantidad de billetes y su denominacion
    int n = billetera.size();

    mem = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>(costo + 1, {INF, INF}));

    pair<int, int> resultadoBacktracking = optipagoBackTracking(billetera, n, costo);
    pair<int, int> resultadoTopDown = optipagoTopDown(billetera, n, costo);

    cout << "Menor cantidad de billetes usados (Backtracking): " << resultadoBacktracking.first << endl;
    cout << "Menor cantidad de billetes usados (TopDown): " << resultadoTopDown.first << endl;

    return 0;
}

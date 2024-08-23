#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 2e5;

pair<int, int> optipagoBackTracking(vector<int>& billetera, int i, int costo) {
    if (costo <= 0) {
        return {0, -costo}; // No se necesita más billetes
    }
    
    if (i == 0) {
        return {INF, INF}; // No se puede realizar el pago
    }

    pair<int, int> sinBillete = optipagoBackTracking(billetera, i - 1, costo);
    
    pair<int, int> conBillete = optipagoBackTracking(billetera, i - 1, costo - billetera[i - 1]);
    conBillete.first += 1; 

    if (conBillete.second < sinBillete.second) {
        return conBillete;
    } else if (conBillete.second == sinBillete.second) {
        return min(conBillete, sinBillete);
    } else {
        return sinBillete;
    }
}


vector<vector<pair<int, int>>> mem;
pair<int, int> optipagoTopDown(vector<int>& billetera, int i, int costo) {

    if (costo <= 0) {
        return mem[i][costo] = {0, -costo}; // No se necesita más billetes
    }

    if (mem[i][costo] != {INF, INF}) return mem[i][costo];

    if (i == 0) {
        return mem[i][costo] = {INF, INF}; // No se puede realizar el pago
    }


    pair<int, int> sinBillete = optipagoBackTracking(billetera, i - 1, costo);
    
    pair<int, int> conBillete = optipagoBackTracking(billetera, i - 1, costo - billetera[i - 1]);
    conBillete.first += 1; 

    if (conBillete.second < sinBillete.second) {
        return  mem[i][costo] = conBillete;
    } else if (conBillete.second == sinBillete.second) {
        return mem[i][costo] = min(conBillete, sinBillete);
    } else {
        return mem[i][costo] = sinBillete;
    }
}

int main() {
    int costo = 14;  // Costo del producto
    vector<int> billetera{2, 3, 5, 10, 20, 20};  // Cantidad de billetes y su denominacion
    int n = billetera.size();

    vector<vector<pair<int, int> >> mem( n+1, (costo+1, {INF, INF}));

    pair<int, int> resultadoBacktracking = optipagoBackTracking(billetera, n, costo);
    pair<int, int> resultadoTopDown = optipagoTopDown(billetera, n, costo);

    cout << "Menor cantidad de billetes usados (Backtracking): " << resultadoBacktracking.first << endl;
    cout << "Menor cantidad de billetes usados (TopDown): " << resultadoTopDown.first << endl;

    return 0;
}

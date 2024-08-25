#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

int INF = 2e5;

map<tuple<int, int, int>, int> mem;

int astroTrade(vector<int>& p, int i, int c, int j){ // i es el dia de compra, j es la cantidad de asteroides, c es la ganancia

    if (i == p.size()) { // Llegamos al final de la semana
        if(j == 0) return c; // Como en 0 es la solucion optima la guardo
        if(j != 0) return -INF;
    }

    tuple<int, int, int> key = make_tuple(i, c, j);

    if(mem.find(key) != mem.end()) return mem[key];

    if( (p.size() - i) < j){ // Si la cantidad de dias restantes es menor a la cantidad de asteroides a vender
        return -INF;
    }

    int comprarAsteroide = astroTrade(p, i + 1, c - p[i] , j + 1);
    int noHacerNada = astroTrade(p, i + 1, c , j);
    int venderAsteroide = astroTrade(p, i + 1, c + p[i] , j - 1);

    return mem[key] = max({comprarAsteroide, noHacerNada, venderAsteroide});
}

int main() {

    vector<int> p{3,6,10};
    cout << "Maxima ganancia posible: " << astroTrade(p , 0, 0, 0) << endl;

    return 0;
}



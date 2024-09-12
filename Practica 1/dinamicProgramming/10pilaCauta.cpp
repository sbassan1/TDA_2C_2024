#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

int INF = 9999;

map<pair<int, vector<int>>, int> memo; // Mapa para memorización


bool sePuedeAgregar(const vector<tuple<int, int>>& cajas, const vector<int>& cajasAgregadas) {
    int n = cajasAgregadas.size();
    
    for (int i = 0; i < n; ++i) {
        int cajaSoporte = get<1>(cajas[cajasAgregadas[i]]); // obtengo el soporte de la caja actual
        int sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += get<0>(cajas[cajasAgregadas[j]]); // sumo el peso de las cajas superiores
            if (cajaSoporte < sum) return false; // Si sobrepasa el soporte, no es válida
        }
    }
    return true;
}

int pilaCauta(vector<tuple<int, int>>& cajas, int n, int i, vector<int> cajasAgregadas, int pesoUltimaCaja) {

    pair<int, vector<int>> estado = {i, cajasAgregadas};

    if (memo.find(estado) != memo.end()) {
        return memo[estado]; // Devolvemos el valor memorizado
    }

    if (n == i) return cajasAgregadas.size(); // Devuelvo la cantidad de cajas al final

     int res = pilaCauta(cajas, n, i + 1, cajasAgregadas, pesoUltimaCaja);

    if (sePuedeAgregar(cajas, cajasAgregadas) && pesoUltimaCaja > get<0>(cajas[i])) {
        cajasAgregadas.push_back(i);
        res = max(pilaCauta(cajas, n, i + 1, cajasAgregadas, get<0>(cajas[i])), pilaCauta(cajas, n, i + 1, cajasAgregadas, pesoUltimaCaja));
        cajasAgregadas.pop_back();  // Deshacer la acción
    }

    memo[estado] = res;
    return res;
}

int main() {
    int n = 5; // cantidad de cajas
    vector<tuple<int, int>> cajas{{19, 15}, {7, 13}, {5, 7}, {6, 8}, {1, 2}}; // Donde las tuplas (int,int) representan peso,soporte

    sort(cajas.begin(), cajas.end(), [](const tuple<int, int>& a, const tuple<int, int>& b) {
        return get<0>(a) > get<0>(b); // Ordenar por peso descendente
    });

    vector<int> cajasAgregadas;

    cout << "Máxima cantidad de cajas: " << pilaCauta(cajas, n, 0, cajasAgregadas, INF) << endl;

    return 0;
}

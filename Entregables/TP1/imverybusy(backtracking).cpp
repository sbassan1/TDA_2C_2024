#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>

using namespace std;

int maximasActividades(vector<pair<int, int>>& tareas, int i, int ultimoSeleccionado, vector<vector<int>>& memo) {
    if (i == tareas.size()) return 0; // llegamos al final del vector

    if (memo[i][ultimoSeleccionado + 1] != -1) return memo[i][ultimoSeleccionado + 1];

    int noHagoActividad = maximasActividades(tareas, i + 1, ultimoSeleccionado, memo);

    int hagoActividad = 0;
    if (ultimoSeleccionado == -1 || !(tareas[ultimoSeleccionado].second > tareas[i].first)) {
        hagoActividad = 1 + maximasActividades(tareas, i + 1, i, memo);
    }

    return memo[i][ultimoSeleccionado + 1] = max(hagoActividad, noHagoActividad);
}


int selectorMaxActividades(vector<pair<int, int>>& tareas, int n) { // Seleccion greedy sin memoizacion o algo antes
    int cont = 1;
    int k = 0;
    for (int m = 1; m < n; m++) {
        if (tareas[m].first >= tareas[k].second) { 
            cont++; 
            k = m;
        }
    }
    return cont;
}


int main() {
    int t; // Numero de tests
    cin >> t;

    vector<int> soluciones;

    while (t > 0) {
        int n; // Numero de pares en este test
        cin >> n;

        vector<pair<int, int>> tareas(n);

        for (int i = 0; i < n; i++) {
            cin >> tareas[i].first >> tareas[i].second;
        }

        sort(tareas.begin(), tareas.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<vector<int>> memo(n, vector<int>(n + 1, -1)); // Inicializo la mem con n espacios en -1

        int resultado = selectorMaxActividades(tareas, n);

        soluciones.push_back(resultado);

        t--;
    }

    for(int i = 0; i < soluciones.size(); i++){
        cout << soluciones[i] << endl;
    }

    return 0;
}

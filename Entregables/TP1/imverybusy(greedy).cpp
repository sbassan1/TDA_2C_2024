#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int greedyDesdeIndice(const vector<pair<int, int>>& tareas, int indiceInicio) {
    int contador = 1;
    int horaUltimaActividad = tareas[indiceInicio].second;

    for (int i = indiceInicio + 1; i < tareas.size(); i++) {
        if (tareas[i].first > horaUltimaActividad) {
            contador++;
            horaUltimaActividad = tareas[i].second;
        }
    }

    return contador;
}

int maximasActividades(vector<pair<int, int>>& tareas) {
    sort(tareas.begin(), tareas.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });

    int maximoContador = 0;

    for (int i = 0; i < tareas.size(); i++) {
        int actividadesRestantes = tareas.size() - i;

        if (actividadesRestantes <= maximoContador) {
            break;
        }

        int contador = greedyDesdeIndice(tareas, i);
        maximoContador = max(maximoContador, contador);
    }

    return maximoContador;
}

int main() {
    int t;
    cin >> t;

    vector<int> soluciones;

    while (t > 0) {
        int n;
        cin >> n;

        vector<pair<int, int>> tareas(n);

        for (int i = 0; i < n; i++) {
            cin >> tareas[i].first >> tareas[i].second;
        }

        int resultado = maximasActividades(tareas);
        soluciones.push_back(resultado);

        t--;
    }

    for (int i = 0; i < soluciones.size(); i++) {
        cout << soluciones[i] << endl;
    }

    return 0;
}

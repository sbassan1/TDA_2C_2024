#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>

using namespace std;

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

        int resultado = selectorMaxActividades(tareas, n);

        cout << resultado << endl;

        t--;
    }

    return 0;
}
